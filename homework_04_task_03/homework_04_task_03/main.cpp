//
//  main.cpp
//  homework_04_task_03
//
//  Created by tkvitko on 21.01.2024.
//


#include <iostream>
#include <string>

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

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size, int& error_code) {
    if (logical_size < 1) {
        error_code = 1;
        return arr;
    } else if (logical_size == 1) {
        logical_size--;
        return arr;
    } else if (logical_size - 1 > actual_size / 3) {
        for (int i = 1; i < logical_size; ++i) {
            arr[i - 1] = arr[i];
        };
        logical_size--;
        return arr;
    } else {
        actual_size /= 3;
        if (actual_size > 0) {
            int* new_array = new int[actual_size] {0};
            for (int i = 1; i < logical_size; ++i) {
                new_array[i - 1] = arr[i];
            };
            delete[] arr;
            logical_size--;
            return new_array;
        } else {
            return arr;
        }
    }
}


int main(int argc, const char * argv[]) {
    int actual_size = 0;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    
    int logical_size = 0;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    
    int* user_array = interactive_create_dynamic_array(logical_size, actual_size);
    if (user_array != nullptr) {
        print_dynamic_array(user_array, logical_size, actual_size);

        std::string answer = " ";
        int error_code = 0;
        while (error_code == 0) {
            std::cout << "Удалить первый элемент? ";
            std::cin >> answer;
            if (answer == "да") {
                user_array = remove_dynamic_array_head(user_array, logical_size, actual_size, error_code);
                print_dynamic_array(user_array, logical_size, actual_size);
                } else {
                    break;
                }
            }
        if (error_code == 1) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!\n";
        }
        std::cout << "Спасибо! Ваш динамический массив: ";
        print_dynamic_array(user_array, logical_size, actual_size);
    }
    return 0;
}
