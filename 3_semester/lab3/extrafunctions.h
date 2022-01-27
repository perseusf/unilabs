#ifndef LAB3_EXTRAFUNCTIONS_H
#define LAB3_EXTRAFUNCTIONS_H

#pragma once

int inputInt() {
    int dim, flag;
    do {
        std::cin >> dim;
        if (dim > 0) {
            flag = 0;
        }
        else {
            std::cout << "Try again." << std::endl << std::endl;
            flag = 1;
        }
    } while (flag);
    return dim;
}

int question(int numofvariants) {
    int choice, flag;
    do {
        std::cin >> choice;
        if (choice <= numofvariants && choice > 0)
            flag = 0;
        else {
            std::cout << "There is no such option. Try again!" << std::endl;
            flag = 1;
        }
    } while (flag);
    return choice;
}

void drawGraph() {
        system("xcopy C:\\dev\\labs_local\\3_semester\\lab3\\cmake-build-debug\\visualization\\matrix.txt C:\\dev\\labs_local\\3_semester\\lab3\\visualization\\matrix.txt /Y");
        system("python C:\\dev\\labs_local\\3_semester\\lab3\\visualization\\drawGraph.py");
}



void exportCSV(GRAPHTYPE graphtype, int max_nodes, int step, const std::string filename) {
    std::ofstream file;
    file.open("measuredtime/" + filename + ".csv");
    int avg_number = 1;


    file << "ShortestPath,,," << std::endl;
    file << ",Time,," << std::endl;
    file << "Nodes,Random,," << std::endl;
    for (int i = 10; i <= max_nodes; i += step) {
        std::cout << i << std::endl;

        long avg_duration = 0;
        //this helps to make graph smoother
        for (int k = 0; k < avg_number; k++) {
            Graph<int> graph(graphtype, i);
            std::vector<int> dist;
            graph.Generate(i, i);
            auto time1 = std::chrono::high_resolution_clock::now();
            dist = graph.FindShortest(0);
            auto time2 = std::chrono::high_resolution_clock::now();
            avg_duration += std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
        }
        long avg_duration_random = avg_duration/avg_number;

        file << i << "," << avg_duration_random << ",," << std::endl;
    }
    file << ",,," << std::endl;
    file.close();
}

template <class T>
void PrintDistances(std::vector<T> dist, int starting_node) {
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != INT_MAX)
            std::cout << starting_node + 1 << " ---> " << i+1 << " = " << dist[i] << std::endl;
        else
            std::cout << starting_node + 1 << " ---> " << i+1 << " = " << "can't reach" << std::endl;
    }
}

#endif //LAB3_EXTRAFUNCTIONS_H
