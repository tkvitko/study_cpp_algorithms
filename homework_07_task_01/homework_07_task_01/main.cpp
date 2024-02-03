//
//  main.cpp
//  homework_07_task_01
//
//  Created by tkvitko on 03.02.2024.
//

#include <iostream>
#include <fstream>


void dfs(bool** graph, int vertex_number,
         int vertex, bool* visited) {
    std::cout << vertex + 1 << " ";
    visited[vertex] = true;
    for (int i = 0; i < vertex_number; ++i) {
        if (graph[vertex][i]) {
            if (!visited[i]) {
                dfs(graph, vertex_number, i, visited);
            }
        }
    }
}

void dfs_main(bool** graph, int vertex_number) {
    bool* visited = new bool[vertex_number]{false};
    for (int i = 0; i < vertex_number; ++i) {
        if (!visited[i]) {
            dfs(graph, vertex_number, i, visited);
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int vertex_number = 0;
    std::ifstream source_file("/Users/tkvitko/c/netology/cpp_algorithms/homework_07_task_01/homework_07_task_01/input.txt");
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
    
    // обход графа в глубину
    std::cout << "Порядок обхода вершин: ";
    dfs_main(graph, vertex_number);
    return 0;
}
