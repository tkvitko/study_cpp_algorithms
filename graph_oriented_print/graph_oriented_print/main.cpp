//
//  main.cpp
//  graph_oriented_print
//
//  Created by tkvitko on 11.02.2024.
//
// Ориентированный граф преставлен матрицей смежности.
// Требуется вывести граф на консоль в удобочитаемом виде.

#include <iostream>
#include <fstream>


void print_graph(bool** graph, int vertex_number) {
    // вывод графа на экран
    std::cout << "Текстовый вид орграфа:" << std::endl;
    
    for (int i = 0; i < vertex_number; ++i) {
        std::cout << i + 1 << ": ";
        bool has_targets = false;
        
        for (int j = 0; j < vertex_number; ++j) {
            if (graph[i][j]) {
                std::cout << j + 1 << " ";
                has_targets = true;
            }
        }
        
        if (!has_targets) {
            std::cout << "нет";
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {

    int vertex_number = 0;
    std::ifstream source_file("/Users/tkvitko/c/netology/cpp_algorithms/graph_oriented_print/graph_oriented_print/input.txt");
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
    
    // вывод на экран
    print_graph(graph, vertex_number);
    return 0;
}
