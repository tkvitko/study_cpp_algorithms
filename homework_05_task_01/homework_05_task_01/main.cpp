//
//  main.cpp
//  homework_05_task_01
//
//  Created by tkvitko on 27.01.2024.
//

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
    
private:
    int* data = nullptr;
    int size = 0;
    
    int get_value_by_index(int index) {
        return data[index];
    }
    
    int get_root() {
        return data[0];
    }
    
    int get_index_of_left_child(int index) {
        int child_index = 2 * index + 1;
        if (child_index < size) {
            return child_index;
        } else {
            throw NoChild();
        }
    }
    
    int get_index_of_right_child(int index) {
        int child_index = 2 * index + 2;
        if (child_index < size) {
            return child_index;
        } else {
            throw NoChild();
        }
    }
    
    int get_index_of_parent(int index) {
        if (index != 0) {
            return (index - 1) / 2;
        } else {
            throw NoParent();
        }
    }
    
    void print_element_info(int level, std::string position, int parent_value, int value) {
        std::cout << level << " " << position << " (" << parent_value << ") " << value << std::endl;
    }

public:
    Heap(int* source_array, int size) {
        this->data = source_array;
        this->size = size;
    }
    
    void print_pyramid() {
        int level = 0;
        std::cout << "0 root " << this->data[0] << std::endl;
        print_children(0, level);
    }
    
    void print_children(int index, int& level) {
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

};

int main(int argc, const char * argv[]) {
    
    int size = 6;
    int* test_array = new int[] {1, 3, 6, 5, 9, 8};
    
//    int size = 8;
//    int* test_array = new int[] {94, 67, 18, 44, 55, 12, 6, 42};
    Heap heap = Heap(test_array, size);
    heap.print_pyramid();
    return 0;
}
