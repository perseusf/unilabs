#ifndef GRAPH_H
#define GRAPH_H
#pragma once

#include <iostream>
#include <limits.h>
#include <chrono>
#include <fstream>
#include <vector>

enum GRAPHTYPE{UNDIRECTED = 1, DIRECTED = 2};

template<class T>
class Graph {
private:
    std::vector<std::vector<T>> adjacencyMatrix;
    int numberOfNodes = 0;
    GRAPHTYPE graphtype = UNDIRECTED;

public:

    //constructors
    Graph(GRAPHTYPE graphtype = UNDIRECTED);
    Graph(GRAPHTYPE graphtype, int numberOfNodes);
    Graph(GRAPHTYPE graphtype, std::vector<std::vector<T>> adjacencyMatrix);

    int GetSize();
    int Get(int i, int j);
    void KeyboardInput(int size);
    void Generate(int size, int maxValue);
    void PrintAdjacencyMatrix();
    void SaveAdjacencyMatrix();

    //algorithms
    std::vector<T> FindShortest(int starting_node);


};

#endif //GRAPH_H