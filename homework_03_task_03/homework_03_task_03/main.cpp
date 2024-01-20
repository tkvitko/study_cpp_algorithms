//
//  main.cpp
//  homework_03_task_03
//
//  Created by tkvitko on 20.01.2024.
//

#include <iostream>

void count_sort(int* arr, int size) {
    int value_min = 10;
    int value_max = 24;
    int k_size = value_max - value_min + 1;
    
    int* counts = new int[k_size] {0};
    for (int i=0; i < size; ++i) {
        counts[arr[i] - value_min] += 1;
    }
    
    int c = 0;
    for (int i=0; i < size; ++i) {
        while (counts[c] == 0) {
            c += 1;
        }
        arr[i] = c + value_min;
        counts[c] -= 1;
    }
}

void demonstrate(int* test_array, int size) {
    // функция для тестов и демонстрации
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << test_array[i] << " ";
    }
    std::cout << std::endl;
    
    count_sort(test_array, size);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << test_array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    int size = 30;
    int* test_array = new int[] {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    demonstrate(test_array, size);
    delete[] test_array;
    
    size = 40;
    test_array = new int[] {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    demonstrate(test_array, size);
    delete[] test_array;
    
    size = 45;
    test_array = new int[] {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
    demonstrate(test_array, size);
    delete[] test_array;
}
