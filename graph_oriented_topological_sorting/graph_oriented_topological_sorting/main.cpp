//
//  main.cpp
//  graph_oriented_topological_sorting
//
//  Created by tkvitko on 11.02.2024.
//
// Ориентированный граф преставлен матрицей смежности.
// Требуется выполнить топологическую сортировку его вершин.

#include <iostream>
#include <fstream>

void append_left(int* source_array, int size, int value) {
    // функция добавления значения в начало списка
    
    for (int i = size - 2; i >= 0; --i) {
        source_array[i + 1] = source_array[i];
    }
    source_array[0] = value;
}

void dfs(bool** graph, int vertex_number,
         int vertex, bool* visited, int* order) {
    // обход в глубину с заолнением поряка
    
    visited[vertex] = true;
    for (int i = 0; i < vertex_number; ++i) {
        if (graph[vertex][i]) {
            if (!visited[i]) {
                dfs(graph, vertex_number, i, visited, order);
            }
        }
    }
    append_left(order, vertex_number, vertex + 1);
}

int* top_sort(bool** graph, int vertex_number) {
    // топологическая сортировка
    
    int* order = new int[vertex_number]();
    bool* visited = new bool[vertex_number]{false};
    for (int i = 0; i < vertex_number; ++i) {
        if (!visited[i]) {
            dfs(graph, vertex_number, i, visited, order);
        }
    }
    return order;
}

int main(int argc, const char * argv[]) {

    int vertex_number = 0;
    std::ifstream source_file("/Users/tkvitko/c/netology/cpp_algorithms/graph_oriented_topological_sorting/graph_oriented_topological_sorting/input.txt");
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

    int* order = top_sort(graph, vertex_number);
    std::cout << "Топологический порядок вершин: ";
    for (int i = 0; i < vertex_number; ++i) {
        std::cout << order[i] << " ";
    }
    return 0;
}
