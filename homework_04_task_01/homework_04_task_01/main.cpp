//
//  main.cpp
//  homework_04_task_01
//
//  Created by tkvitko on 21.01.2024.
//

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i=0; i < actual_size; ++i) {
        if  (i < logical_size) {
            std::cout << arr[i];
        } else {
            std:: cout << "_";
        }
        std::cout << " ";
    }
    std::cout << "\n";
};

int* interactive_create_dynamic_array(int logical_size, int actual_size) {
    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
        return nullptr;
    } else {
        int* new_array = new int[actual_size];
        for (int i=0; i < logical_size; ++i) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> new_array[i];
        }
        return new_array;
    }
}

int main(int argc, const char * argv[]) {
    int actual_size = 0;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    
    int logical_size = 0;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    
    int* new_array = interactive_create_dynamic_array(logical_size, actual_size);
    if (new_array != nullptr) {
        print_dynamic_array(new_array, logical_size, actual_size);
    }
    return 0;
}
