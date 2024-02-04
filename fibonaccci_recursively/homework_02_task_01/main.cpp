//
//  main.cpp
//  homework_02_task_01
//
//  Created by tkvitko on 14.01.2024.
//
// Рекурсивная реализация поиска чисел Фибоначчи и анализ алгоритмической сложности

#include <iostream>

int fibonaccci(int number) {
    // сложность:
    // по скорости - О(2^n), т.к. на каждом шаге функция вызывается рекурсивно 2 раза
    // по памяти - O(1), т.к. никакой памяти не тратится
    
    if (number == 1 || number == 2) {
        return 1;
    } else {
        return fibonaccci(number - 1) + fibonaccci(number - 2);
    }
}

int main(int argc, const char * argv[]) {
    
    int number = 0;
    std::cout << "Введите номер: " << std::endl;
    std::cin >> number;
    std::cout << "Число фибоначчи на позиции " << number << ": " << fibonaccci(number) << std::endl;
    return 0;
}
