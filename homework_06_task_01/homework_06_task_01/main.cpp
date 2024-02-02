//
//  main.cpp
//  homework_06_task_01
//
//  Created by tkvitko on 02.02.2024.
//

#include <iostream>
#include <string>

int simple_string_hash(std::string source_string) {
    int result = 0;
    for (int i = 0; i < source_string.length(); ++i) {
        result += int(source_string[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::string user_string;
    do {
        std::cout << "Введите строку: ";
        std::cin >> user_string;
        std::cout << "Наивный хэш строки " << user_string << " = " << simple_string_hash(user_string) << std::endl;
    } while (user_string != "exit");
    return 0;
}
