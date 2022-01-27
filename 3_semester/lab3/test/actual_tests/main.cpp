#include <iostream>
#include "../../graph.cpp"
#include "../../extrafunctions.h"
#include "gtest/gtest.h"
using namespace std;

int numberOfNodes = 100;

TEST(ConstructorFromMatrix, test) {
    std::vector<std::vector<int>> data;
    for (int i = 0; i < numberOfNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < numberOfNodes; j++) {
            row.push_back(0);
        }
        data.push_back(row);
    }

    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j < numberOfNodes; j++) {
            data[i][j] = (j*i - 2);
        }
    }

    Graph<int> graph(UNDIRECTED, data);
    bool isFine = true;
    for (int i = 0; i < graph.GetSize(); i++) {
        for (int j = 0; j < graph.GetSize(); j++) {
            if(graph.Get(i, j) != data[i][j])
                isFine = false;
        }
    }
    ASSERT_TRUE(isFine);
}

TEST(ShortestPath, test) {
    std::vector<std::vector<int>> data;
    for (int i = 0; i < numberOfNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < numberOfNodes; j++) {
            row.push_back(0);
        }
        data.push_back(row);
    }

    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j < numberOfNodes; j++) {
            if (i == j)
                data[i][j] = INT_MAX;
            data[i][j] = 1;
        }
    }

    Graph<int> graph(UNDIRECTED, data);
    std::vector<int> result = graph.FindShortest(0);
    std::vector<int> trueresult;
    trueresult.push_back(0);
    for (int i = 1; i < numberOfNodes; i++) {
        trueresult.push_back(1);
    }

    bool isFine = true;
    for (int i = 0; i < graph.GetSize(); i++) {
        if (result[i] != trueresult[i])
            isFine = false;
    }
    ASSERT_TRUE(isFine);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
