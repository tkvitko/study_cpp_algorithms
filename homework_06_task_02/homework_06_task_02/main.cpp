//
//  main.cpp
//  homework_06_task_02
//
//  Created by tkvitko on 02.02.2024.
//

#include <iostream>
#include <string>

long real_string_hash(std::string source_string, const int p, const int n) {
    long result = 0;
    long mult = 1;
    for (int i = 0; i < source_string.length(); ++i) {
        result += mult * int(source_string[i]);
        mult *= p;
    }
    result %= n;
    return result;
}

int main(int argc, const char * argv[]) {
    std::string user_string;
    int p, n = 0;
    
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    
    do {
        std::cout << "Введите строку: ";
        std::cin >> user_string;
        std::cout << "Хэш строки " << user_string << " = " << real_string_hash(user_string, p, n) << std::endl;
    } while (user_string != "exit");
    return 0;
}

