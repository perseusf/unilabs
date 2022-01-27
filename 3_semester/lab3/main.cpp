#include <iostream>
#include <string>
#include "graph.cpp"
#include "extrafunctions.h"

enum STATUS{RUN = 1, STOP = 0};
enum OPERATION{MEASURE_TIME = 1, SHORTEST_PATH = 2};
enum INPUT{AUTOMATIC = 1, KEYBOARD = 2};

int main() {

    STATUS program_status = RUN;
    GRAPHTYPE graph_type;
    OPERATION operation_type;
    INPUT input_type;
    int number_of_nodes;
    int start;
    Graph<int> graph;

    do {
        std::cout << std::endl << "Orientation of the graph:\n1. Undirected\n2. Directed" << std::endl;
        std::cout << "Select: ";
        graph_type = GRAPHTYPE(question(2));

        std::cout << std::endl << "Number of nodes: ";
        number_of_nodes = inputInt();

        std::cout << std::endl <<"Operations:\n1. Measure time\n2. Shortest path\n"<< std::endl;
        std::cout << "Select: ";
        operation_type = OPERATION(question(2));

        std::cout << std::endl <<"Input type:\n1. Automatic\n2. Keyboard" << std::endl;
        std::cout << "Select: ";
        input_type = INPUT(question(2));

        switch(graph_type) {
            case UNDIRECTED:
                switch(operation_type) {
                    case MEASURE_TIME:
                        exportCSV(UNDIRECTED, 10000, 1000, "timemeasurementUNDIRECTED");
                        break;
                    case SHORTEST_PATH:
                        graph = Graph<int>(UNDIRECTED, number_of_nodes);
                        switch(input_type) {
                            case AUTOMATIC:
                                int maxValue;
                                std::cout << std::endl << "Enter max distance: ";
                                maxValue = inputInt();
                                graph.Generate(number_of_nodes, maxValue);
                                break;
                            case KEYBOARD:
                                graph.KeyboardInput(number_of_nodes);
                                break;
                        }
                        if (graph.GetSize() <= 30)  //in order not to slow down the program graphs bigger than 30 nodes will not be printed
                            graph.PrintAdjacencyMatrix();
                        graph.SaveAdjacencyMatrix();
                        std::cout << "Enter starting node: " << std::endl;
                        start = inputInt();
                        start--;
                        std::vector<int> dist = graph.FindShortest(start);
                        PrintDistances(dist, start);
                        int toDraw = 0;
                        std::cout << "Draw the graph? Yes(1), No(0): ";
                        toDraw = inputInt();
                        if (toDraw == 1)
                            drawGraph();
                        break;
                }
                break;
            case DIRECTED:
                switch(operation_type) {
                    case MEASURE_TIME:
                        exportCSV(DIRECTED, 10000, 1000, "timemeasurementDIRECTED");
                        break;
                    case SHORTEST_PATH:
                        graph = Graph<int>(DIRECTED, number_of_nodes);
                        switch(input_type) {
                            case AUTOMATIC:
                                int maxValue;
                                std::cout << std::endl << "Enter max distance: ";
                                maxValue = inputInt();
                                graph.Generate(number_of_nodes, maxValue);
                                break;
                            case KEYBOARD:
                                graph.KeyboardInput(number_of_nodes);
                                break;
                        }
                        if (graph.GetSize() <= 30)  //in order not to slow down the program graphs bigger than 30 nodes will not be printed
                            graph.PrintAdjacencyMatrix();
                        graph.SaveAdjacencyMatrix();
                        std::cout << "Enter starting node: " << std::endl;
                        start = inputInt();
                        start--;
                        std::vector<int> dist = graph.FindShortest(start);
                        PrintDistances(dist, start);
//                        drawGraph();
                        break;
                }
                break;
        }
        std::cout << std::endl << "Continue or close the program?\n1. Continue\n2. Close" << std::endl;
        std::cout << "Select: ";
        program_status = STATUS(question(2));
        if (program_status == STOP)
            std::cout << "Bye!" << std::endl;
    } while (program_status == RUN);

    return 0;
}


