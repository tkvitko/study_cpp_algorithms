//
//  main.cpp
//  homework_07_task_02
//
//  Created by tkvitko on 03.02.2024.
//

#include <iostream>
#include <fstream>


void bfs(bool** graph, int vertex_number, int start) {
    bool* visited = new bool[vertex_number]{false};
    int* queue = new int[vertex_number]{-1};
    int current_queue_position = 0;
    
    if (!visited[start]) {
        queue[current_queue_position] = start;
        current_queue_position++;
        for (int i = 0; i < vertex_number; ++i) {
            int vertex = queue[i];
            std::cout << vertex + 1 << " ";
            visited[vertex] = true;
            for (int j = 0; j < vertex_number; ++j) {
                if (graph[vertex][j]) {
                    if (!visited[j]) {
                        queue[current_queue_position] = j;
                        current_queue_position++;
                    }
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int vertex_number = 0;
    std::ifstream source_file("/Users/tkvitko/c/netology/cpp_algorithms/homework_07_task_02/homework_07_task_02/input.txt");
    source_file >> vertex_number;
    
    // создание двумерного массива для хранения графа
    bool **graph = new bool *[vertex_number];
    for (int i = 0; i < vertex_number; ++i) {
        graph[i] = new bool[vertex_number]();
    }
    
    // заполнение графа данными из файла
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            source_file >> graph [i][j];
            }
        }
    
    // вывод графа на экран
//    for (int i = 0; i < vertex_number; ++i) {
//        for (int j = 0; j < vertex_number; ++j) {
//          std::cout << graph[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
    
    // обход графа в ширину
    int start = 0;
    std::cout << "В графе " << vertex_number << " вершин. Введите номер вершины, с которой начнётся обход: ";
    std::cin >> start;
    std::cout << "Порядок обхода вершин: ";
    bfs(graph, vertex_number, start);
    return 0;
}
