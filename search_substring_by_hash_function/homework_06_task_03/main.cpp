//
//  main.cpp
//  homework_06_task_03
//
//  Created by tkvitko on 02.02.2024.
//
// Реализация поиска подстроки в строке с помощью упрощённого алгоритма Рабина-Карпа (через наивную хеш-функцию).


#include <iostream>
#include <string>


int simple_string_hash(std::string source_string) {
    int result = 0;
    for (int i = 0; i < source_string.length(); ++i) {
        result += int(source_string[i]);
    }
    return result;
}


int find_substring_light_rabin_karp(std::string source_string, std::string sub_string) {
    
    long k = sub_string.length();
    int slice_hash = 0;
    int sub_string_hash = simple_string_hash(sub_string);
    
    for (int i = 0; i < source_string.length(); ++i) {
        
        if (i == 0) {
            std::string current_slice = source_string.substr(0, k);
            slice_hash = simple_string_hash(current_slice);
        } else {
            slice_hash -= int(source_string[i - 1]);
            slice_hash += int(source_string[i + k - 1]);
        }
        
        if (slice_hash == sub_string_hash) {
            bool good = true;
            for (int j = 0; j < k; ++j) {
                if (source_string[i + j] != sub_string[j]) {
                    good = false;
                }
            }
            if (good) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    std::string user_string, user_sub_string;
    
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> user_string;
    
    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> user_sub_string;
        int index = find_substring_light_rabin_karp(user_string, user_sub_string);
        if (index == -1) {
            std::cout << "Подстрока " << user_sub_string << " не найдена" << std::endl;
        } else {
            std::cout << "Подстрока " << user_sub_string << " найдена по индексу " << index << std::endl;
        }
    } while (user_sub_string != "exit");
    return 0;
}
