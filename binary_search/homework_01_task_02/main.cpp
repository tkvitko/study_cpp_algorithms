//
//  main.cpp
//  homework_01_task_02
//
//  Created by tkvitko on 13.01.2024.
//
// Используя алгоритм бинарного поиска, ищется количество элеметнтов списка больше переданного порога


#include <iostream>
#include <iostream>

int get_number_of_elements_greater_then_limit(int *array, int size, int limit) {
  int left = 0;
  int right = size - 1;
  if (limit >= array[right]) {
      return 0;
  }
    
  while (left < right) {
    int middle = (left + right) / 2;
    if (array[middle] > limit) {
     right = middle;
    } else {
     left = middle + 1;
    }
  }
  return size - left;
}

int main() {
    int size = 9;
    int test_array[9] {14, 16, 19, 32, 32, 32, 56, 69, 72};

    int limit = 0;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> limit;
    
    int result = get_number_of_elements_greater_then_limit(test_array, size, limit);
    std::cout << "Количество элементов в массиве больших, чем " << limit << ": " << result << std::endl;
}
