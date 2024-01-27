//
//  main.cpp
//  homework_03_task_01
//
//  Created by tkvitko on 16.01.2024.
//

#include <iostream>

int* merge(int* arr_1, int size_1,
           int* arr_2, int size_2) {
    // функция слияния 2х массивов в 1
    
    int i = 0;
    int j = 0;
    int k = 0;
    int result_size = size_1 + size_2;
    int* merged_array = new int[result_size] {0};
    
    while (i != size_1 || j != size_2) {
        
        if (i == size_1) {
            merged_array[k] = arr_2[j];
            ++j;
        } else if (j == size_2) {
            merged_array[k] = arr_1[i];
            ++i;
        } else {
        
            if (arr_1[i] < arr_2[j]) {
                merged_array[k] = arr_1[i];
                ++i;
            } else {
                merged_array[k] = arr_2[j];
                ++j;
            }
        }
        
        ++k;
    }
    return merged_array;
    
}

int* merge_sort(int* arr, int size) {
    if (size == 1) {
        // если длина массива уже 1, ничего не делаем
        int val = arr[0];
        delete[] arr; //удаляем входной массив
        return new int[1] {val}; //создаём новый выходной
    } else {
        
        // разбиваем массив на 2 половинки
        int size_left = size/2;
        int size_right = size - size_left;
        int* left = new int[size_left] {0};
        int* right = new int[size_right] {0};
        for (int i = 0; i < size; ++i) {
            if (i < size_left) {
                left[i] = arr[i];
            } else {
                right[i - size_left] = arr[i];
            }
        };
        
        // рекурсивно сортируем каждую половинку
        int* left_sorted = merge_sort(left, size_left);
        int* right_sorted = merge_sort(right, size_right);
//        for (int i = 0; i < size_left; ++i) {
//            std::cout << left_sorted[i] << " ";
//        }
//        std::cout << std::endl;
//        for (int i = 0; i < size_right; ++i) {
//            std::cout << right_sorted[i] << " ";
//        }
//        std::cout << std::endl;
        
        // сливаем отсортированные половинки и возвращаем
        int* merged = merge(left_sorted, size_left, right_sorted, size_right);
        delete[] arr;
        delete[] left_sorted;
        delete[] right_sorted;
        return merged;
    }
}

int main(int argc, const char * argv[]) {
    
    int size = 10;
    int* test_array = new int[] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
//    int size = 7;
//    int* test_array = new int[] {38, 27, 43, 3, 9, 82, 10};
    int* sorted_array = new int[size] {0};
    sorted_array = merge_sort(test_array, size);

    for (int i = 0; i < size; ++i) {
        std::cout << sorted_array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
    
}
