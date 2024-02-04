//
//  main.cpp
//  homework_05_task_02
//
//  Created by tkvitko on 27.01.2024.
//
// Реализация хранения пирамиды в массиве.
// Вывод такой пирамиды на экран.
// Реализация перемещения по узлам пирамиды командами пользователя.

#include <iostream>

class NoChild : public std::exception {
public:
    const char* what() const noexcept override {
        return "Нет потомка";
    }
};

class NoParent : public std::exception {
public:
    const char* what() const noexcept override {
        return "Нет предка";
    }
};


class Heap {
    // пирамида
    
private:
    int* data = nullptr;
    int size = 0;
    int current_position = 0;
    
    int get_value_by_index(int index) {
        // получить значение узла по номеру в массиве
        return data[index];
    }
    
    int get_root() {
        // получить корень пирамиды
        return data[0];
    }
    
    int get_index_of_left_child(int index) {
        // получить индекс левого ребенка текущего узла (по индексу текущего узла)
        int child_index = 2 * index + 1;
        if (child_index < size) {
            return child_index;
        } else {
            throw NoChild();
        }
    }
    
    int get_index_of_right_child(int index) {
        // получить индекс правого ребенка текущего узла (по индексу текущего узла)
        int child_index = 2 * index + 2;
        if (child_index < size) {
            return child_index;
        } else {
            throw NoChild();
        }
    }
    
    int get_index_of_parent(int index) {
        // получить индекс родителя текущего узла (по индексу текущего узла)
        if (index != 0) {
            return (index - 1) / 2;
        } else {
            throw NoParent();
        }
    }
    
    std::string get_relative_position(int index) {
        // получить относительную позицию (левый или правый ребенок) узла (по индексу узла)
        if (index == 0) {
            return "root";
        } else if (index == 1) {
            return "left";
        } else if (index == 2) {
            return "right";
        } else {
            float temp_float = (index - 1) / 2;
            int temp_int = (index - 1) / 2;
            if (temp_int == temp_float) {
                return "left";
            }
            return "right";
        }
    }
    
    void print_element_info(int level, std::string position, int parent_value, int value) {
        // вывести на экран информацию об элементе
        if (parent_value != 0) {
            std::cout << level << " " << position << " (" << parent_value << ") " << value << std::endl;
        } else {
            std::cout << level << " " << position << " " << value << std::endl;
        }
    }

public:
    Heap(int* source_array, int size) {
        // конструктор пирамиды
        this->data = source_array;
        this->size = size;
    }
    
    void print_pyramid() {
        // вывод пирамиды на экран
        int level = 0;
        std::cout << "0 root " << this->data[0] << std::endl;
        print_children(0, level);
    }
    
    void print_children(int index, int& level) {
        // рекурсивный вывод детей элемента
        level++;
        int current_value = get_value_by_index(index);
        try {
            int left_child_index = get_index_of_left_child(index);
            int left_child = get_value_by_index(left_child_index);
            print_element_info(level, "left", current_value, left_child);
            print_children(left_child_index, level);
        } catch (const NoChild& e) {
            }
        
        try {
            int right_child_index = get_index_of_right_child(index);
            int right_child = get_value_by_index(right_child_index);
            print_element_info(level, "right", current_value, right_child);
            print_children(right_child_index, level);
        } catch (const NoChild& e) {
            }
        level--;
    }
    
    void go_up(int& current_position) {
        // переместиться на родителя
        if (current_position == 0) {
            throw NoParent();
        } else {
            current_position = get_index_of_parent(current_position);
        }
    }
    
    void go_left(int& current_position) {
        // переместиться на левого ребенка
        try {
            current_position = get_index_of_left_child(current_position);
        } catch (const NoChild& e) {
            throw NoChild();
        }
    }
    
    void go_right(int& current_position) {
        // переместиться на правого ребенка
        try {
            current_position = get_index_of_right_child(current_position);
        } catch (const NoChild& e) {
            throw NoChild();
        }
    }
    
    void print_travel_position(int level, std::string position, int parent_value, int value) {
        // вывести на экран текущую позицию пользователя на пирамиде
        std::cout << "Вы находитесь здесь: ";
        print_element_info(level, position, parent_value, value);
    }
    
    void travel() {
        // функция для перемещения пользователя по пирамиде (начинается с корня)
        int level = 0;
        int parent_value = 0;
        int value = get_value_by_index(current_position);
        std::string position = "root";
        bool exit = false;
        std::string user_command = "";
        
        while (!exit) {
            print_travel_position(level, position, parent_value, value);
            std::cout << "Введите команду: ";
            std::cin >> user_command;
            
            if (user_command == "exit") {
                break;
            } else {
                try {
                    if (user_command == "up") {
                        go_up(current_position);
                        level--;
                        position = get_relative_position(current_position);
                    } else if (user_command == "left") {
                        go_left(current_position);
                        level++;
                        position = "left";
                    } else if (user_command == "right") {
                        go_right(current_position);
                        level++;
                        position = "right";
                    }
                    value = get_value_by_index(current_position);
                    try {
                        parent_value = get_value_by_index(get_index_of_parent(current_position));
                    } catch (const NoParent& e) {
                        parent_value = 0;
                    }
                    std::cout << "Ok" << std::endl;
                } catch (const NoChild& e) {
                    std::cout << "Ошибка! Отсутствует потомок" << std::endl;
                } catch (const NoParent& e) {
                    std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
//    int size = 6;
//    int* test_array = new int[] {1, 3, 6, 5, 9, 8};
    
    int size = 8;
    int* test_array = new int[] {94, 67, 18, 44, 55, 12, 6, 42};
    Heap heap = Heap(test_array, size);
    heap.print_pyramid();
    heap.travel();
    return 0;
}
