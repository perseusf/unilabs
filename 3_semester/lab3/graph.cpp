#include "graph.h"
#include "extrafunctions.h"

template <class T>
Graph<T>::Graph(GRAPHTYPE graphtype) {
    this->graphtype = graphtype;
    this->adjacencyMatrix = std::vector<std::vector<T>>();
    this->numberOfNodes = 0;
}

template <class T>
Graph<T>::Graph(GRAPHTYPE graphtype, int numberOfNodes) {
    this->graphtype = graphtype;
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < numberOfNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < numberOfNodes; j++) {
            row.push_back(0);
        }
        matrix.push_back(row);
    }
    this->numberOfNodes = numberOfNodes;
    this->adjacencyMatrix = matrix;
}

template <class T>
Graph<T>::Graph(GRAPHTYPE graphtype, std::vector<std::vector<T>> adjacencyMatrix) {
    this->graphtype = graphtype;
    this->adjacencyMatrix = adjacencyMatrix;
    this->numberOfNodes = adjacencyMatrix.size();
}

template <class T>
int Graph<T>::GetSize() {
    return this->numberOfNodes;
}

template <class T>
int Graph<T>::Get(int i, int j) {
    return this->adjacencyMatrix[i][j];
}

template <class T>
void Graph<T>::KeyboardInput(int size) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < numberOfNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < numberOfNodes; j++) {
            row.push_back(0);
        }
        matrix.push_back(row);
    }
    if (graphtype == UNDIRECTED) {
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                T item;
                std::cout << i + 1 << " ---> " << j + 1 << ":";
                std::cin >> item;
                if (item == 0) {
                    matrix[i][j] = INT_MAX;
                    matrix[j][i] = INT_MAX;
                    continue;
                }
                matrix[i][j] = item;
                matrix[j][i] = item;
            }
        }
    }
    if (graphtype == DIRECTED) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                T item;
                std::cout << i + 1 << " ---> " << j + 1 << ":";
                std::cin >> item;
                if (item == 0) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                matrix[i][j] = item;
            }
        }
    }
    this->adjacencyMatrix = matrix;
    this->numberOfNodes = size;
}

template <class T>
void Graph<T>::Generate(int size, int maxValue) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < numberOfNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < numberOfNodes; j++) {
            row.push_back(0);
        }
        matrix.push_back(row);
    }

    if (graphtype == UNDIRECTED) {
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                T item;
                if (size < 5)
                    item = std::rand() % maxValue;
                else if (size >=5 && size < 30)
                    item = std::rand() % maxValue;
//                    item = (std::rand()%maxValue)*(std::rand()%2);
                else
                    item = std::rand() % maxValue;
//                    item = (std::rand()%maxValue)*(std::rand()%2)*(std::rand()%2)*(std::rand()%2);
                if (item == 0) {
                    matrix[i][j] = INT_MAX;
                    matrix[j][i] = INT_MAX;
                    continue;
                }
                matrix[i][j] = item;
                matrix[j][i] = item;
            }
        }
    }
    if (graphtype == DIRECTED) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                T item;
                if (size < 5)
                    item = std::rand() % maxValue;
                else if (size >=5 && size < 30)
                    item = std::rand() % maxValue;
//                    item = (std::rand()%maxValue)*(std::rand()%2);
                else
                    item = std::rand() % maxValue;
//                    item = (std::rand()%maxValue)*(std::rand()%2)*(std::rand()%2)*(std::rand()%2);
                if (item == 0) {
                    matrix[i][j] = INT_MAX;
                    continue;
                }
                matrix[i][j] = item;
            }
        }
    }

    this->adjacencyMatrix = matrix;
    this->numberOfNodes = size;
}


template <class T>
void Graph<T>::SaveAdjacencyMatrix() {
    std::ofstream file;
    file.open("visualization/matrix.txt");
    if (file.is_open()) {
        for (int i = 0; i < this->GetSize(); i++) {
            for (int j = 0; j < this->GetSize(); j++) {
                if(this->Get(i,j) == INT_MAX && (j < this->GetSize() - 1)) {
                    file << 0 << " ";
                    continue;
                } else if (this->Get(i,j) == INT_MAX && (j = this->GetSize() - 1)){
                    file << 0;
                    continue;
                }
                if (j < this->GetSize() - 1)
                    file << this->adjacencyMatrix[i][j] << " ";
                else
                    file << this->adjacencyMatrix[i][j];
            }
            file << std::endl;
        }
    }
    file.close();
}

template <class T>
void Graph<T>::PrintAdjacencyMatrix() {
    for (int i = 0; i < this->GetSize(); i++) {
        for (int j = 0; j < this->GetSize(); j++) {
            if(this->Get(i,j) == INT_MAX) {
                std::cout << "0" << " ";
                continue;
            }
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T>
std::vector<T> Graph<T>::FindShortest(int starting_node) {
    bool visited[numberOfNodes]; //посещенные вершины
    std::vector<T> distance; //длины кратчайших путей

    for(int j = 0; j < numberOfNodes; j++) {
        distance.push_back(this->Get(starting_node, j)); //расстояния от starting_node до j
        visited[j] = false;
    }

    distance[starting_node] = 0;
    int index = 0; //индекс вершины с минимальным расстоянием
    int current_node = 0;

    for (int i = 0; i < numberOfNodes; i++) {

        //выбираем из непосещенных вершин вершину с минимальным расстоянием
        int min = INT_MAX;
        for (int j = 0; j < numberOfNodes; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                index = j;
            }
        }

        //пересчитываем минимальные расстояния до вершин
        current_node = index;
        visited[current_node] = true; //отмечаем, что мы в ней уже были
        for(int j = 0; j < numberOfNodes; j++) {
            if (!visited[j] && this->Get(current_node, j) != INT_MAX && (distance[current_node] + this->Get(current_node, j) < distance[j])) {
                distance[j] = distance[current_node] + this->Get(current_node, j);
            }
        }
    }

    return distance;
}


