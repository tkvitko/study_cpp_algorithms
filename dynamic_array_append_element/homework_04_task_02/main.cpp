//
//  main.cpp
//  homework_04_task_02
//
//  Created by tkvitko on 21.01.2024.
//
// Реализация динамического массива (обладает фактическим (по памяти) и логическим (по элементам) размером)
// Реализация добавления элемента в динамический массив (если места уже нет, фактический размер увеличивается в 2 раза)

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    // вывод динамического массива на экран
    
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
    // создание динамического массива по требованиям пользователя
    
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

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int elem) {
    // добавление элемента в динамический массив
    
    if (logical_size < actual_size) {
        arr[logical_size] = elem;
        logical_size++;
        return arr;
    } else {
        // если запаса уже нет, добавляется запас длиной в текущее количество элементов
        actual_size *= 2;
        int* new_array = new int[actual_size] {0};
        for (int i = 0; i < logical_size; ++i) {
            new_array[i] = arr[i];
        };
        new_array[logical_size] = elem;
        logical_size++;
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

        int elem = -1;
        while (elem != 0) {
            std::cout << "Введите элемент для добавления: ";
            std::cin >> elem;
            if (elem != 0) {
                new_array = append_to_dynamic_array(new_array, logical_size, actual_size, elem);
                print_dynamic_array(new_array, logical_size, actual_size);
            }
        }
        std::cout << "Спасибо! Ваш массив: ";
        print_dynamic_array(new_array, logical_size, actual_size);
    }
    return 0;
}
