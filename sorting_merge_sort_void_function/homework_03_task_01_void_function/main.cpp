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

void merge_sort(int* arr, int size) {
    if (size > 1) {

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

        merge_sort(left, size_left);
        merge_sort(right, size_right);
        arr = merge(left, size_left, right, size_right);
    }
}

int main(int argc, const char * argv[]) {

    int size = 10;
    int* test_array = new int[] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    merge_sort(test_array, size);

    for (int i = 0; i < size; ++i) {
        std::cout << test_array[i] << " ";
    }
    std::cout << std::endl;
    return 0;

}
