//
//  main.cpp
//  homework_03_task_02
//
//  Created by tkvitko on 19.01.2024.
//
// Реализация сортировки quicksort ("быстрая" сортировка)

#include <iostream>

void swap_elements(int* arr, int idx_1, int idx_2) {
    // функция смены мест 2х элементов друг с другом
    
    int temp = arr[idx_1];
    arr[idx_1] = arr[idx_2];
    arr[idx_2] = temp;
}

int pivoting(int* arr, int size, int pivot_idx) {
    // Пивотирование
    
    int left_idx = 0;
    int right_idx = size - 1;
    int pivot_elem = arr[pivot_idx];
    
    while (true) {
        while (arr[left_idx] < pivot_elem) {
            left_idx += 1;
        };
        while (arr[right_idx] > pivot_elem) {
            right_idx -= 1;
        };
        
        if (left_idx >= right_idx) {
            return left_idx;
        }
        swap_elements(arr, left_idx, right_idx);
        left_idx += 1;
        right_idx -= 1;
        }
}

void quick_sort(int* arr, int size) {
    // быстрая сортировка через пивотирование
    
    if (size != 1) {
        int pi = size / 2;
        int border = pivoting(arr, size, pi);
        quick_sort(arr, border);
        quick_sort(arr + border, size - border);
    }
}

void demonstrate(int* test_array, int size) {
    // функция для тестов и демонстрации
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << test_array[i] << " ";
    }
    std::cout << std::endl;
    
    quick_sort(test_array, size);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << test_array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    int size = 10;
    int* test_array = new int[] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    demonstrate(test_array, size);
    delete[] test_array;

    size = 15;
    test_array = new int[] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    demonstrate(test_array, size);
    delete[] test_array;

    size = 18;
    test_array = new int[] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    demonstrate(test_array, size);
    delete[] test_array;

    // тесты пивотирования
//    int size = 5;
//    int* test_array = new int[size] {0, 44, 10, 55, 2};
//    int limit = pivoting(test_array, size, 1);
//    std::cout << limit << std::endl;
//    for (int i = 0; i < size; ++i) {
//        std::cout << test_array[i] << " ";
//    }

    std::cout << std::endl;
    return 0;
}
