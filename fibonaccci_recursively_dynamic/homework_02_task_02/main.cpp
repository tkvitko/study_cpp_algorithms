//
//  main.cpp
//  homework_02_task_02
//
//  Created by tkvitko on 14.01.2024.
//
// Рекурсивная реализация поиска чисел Фибоначчи с применением динамического программирования к рекурсии

#include <iostream>

unsigned long fibonaccci(int number, unsigned long* data) {
    // сложность:
    // по скорости - О(n), т.к. в половине случаев посчитанное значение уже есть в кеше
    // по памяти - O(n), тратится память на хранение промежуточных вычислений
    
    unsigned long value_from_cache = data[number];
    if (value_from_cache != 0) {
        // если значение было посчитано ранее, забираем из кеша
        // дебаг:
        // std::cout << "возврат из кеша для запроса " << number << " результата " << value_from_cache << std::endl;
        return value_from_cache;
    }
    
    if (number == 1 || number == 2) {
        int result =  1;
        data[number] = result;  // добавляем посчитанное значение в кеш
        return result;
    } else {
        unsigned long result = fibonaccci(number - 1, data) + fibonaccci(number - 2, data);
        data[number] = result;  // добавляем посчитанное значение в кеш
        return result;
    }
}

int main(int argc, const char * argv[]) {
    
    int number = 0;
    std::cout << "Введите номер: ";
    std::cin >> number;
    
    unsigned long* cache = new unsigned long[number + 1] {0};
    std::cout << "Число фибоначчи на позиции " << number << ": " << fibonaccci(number, cache) << std::endl;
    delete[] cache;
    return 0;
}
