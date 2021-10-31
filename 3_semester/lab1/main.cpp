#include <ctime>
#include "src/functions.h"
using namespace std;

int setLength() {
    int dim, flag;
    do {
        cin >> dim;
        if (dim > 0) {
            flag = 0;
        }
        else {
            cout << "Try again." << endl << endl;
            flag = 1;
        }
    } while (flag);
    return dim;
}

int question(int numofvariants) {
    int choice, flag;
    do {
        cin >> choice;
        if (choice <= numofvariants && choice > 0)
            flag = 0;
        else {
            cout << "There is no such option. Try again!" << endl;
            flag = 1;
        }
    } while (flag);
    return choice;
}

int main() {

    srand(time(nullptr));
    int sorting_mode, sequence_type, closing, seq_length;
    int maxValue = 10000;

    do {

        cout << endl << "Choose a structure:\n1. Dynamic array\n2. Linked list" << endl;
        cout << "Select: ";
        sequence_type = question(2);

        cout << endl <<"Choose a sorting mode:\n1. CSV table for graphs\n2. Comparison\n3. BubbleSort\n4. SelectionSort\n5. InsertionSort\n6. MergeSort\n7. QuickSort\n8. ShellSort"<< endl;
        cout << "Select: ";
        sorting_mode = question(8);

        cout << endl << "Length: ";
        seq_length = setLength();

        Sequence<int> *seq;
        string sort_name;
        string filename;

        switch(sequence_type) {
            case 1: //array based
                switch(sorting_mode) {
                    case 1: //graphs
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        exportCSV(seq, cmp, 10000, 500, "arraycomparison");
                        cout << "Please, check file sortscomparison/arraycomparison.csv" << endl;
                        break;
                    case 2: //comparison
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        filename = "arrayAllSorts";
                        exportTXTall(seq, cmp, filename);
                        cout << "Please, check file sorts/" + filename + ".txt" << endl;
                        break;
                    case 3: //bubble
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arrayBubbleSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 4: //selection
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arraySelectionSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 5: //insertion
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arrayInsertionSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 6: //merge
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arrayMergeSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 7: //quick
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arrayQuickSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 8: //shell
                        seq = (Sequence<int> *) new ArraySequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "arrayShellSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                }
                break;

            case 2: //list based
                switch(sorting_mode) {
                    case 1: //graphs
                        seq = (Sequence<int> *) new ListSequence<int>;
                        exportCSV(seq, cmp, 1500, 200, "listcomparison");
                        cout << "Please, check file sortscomparison/listcomparison.csv" << endl;
                        break;
                    case 2: //comparison
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        filename = "listAllSorts";
                        exportTXTall(seq, cmp, filename);
                        cout << "Please, check file sorts/" + filename + ".txt" << endl;
                        break;
                    case 3: //bubble
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listBubbleSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 4: //selection
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listSelectionSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 5: //insertion
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listInsertionSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 6: //merge
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listMergeSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 7: //quick
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listQuickSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                    case 8: //shell
                        seq = (Sequence<int> *) new ListSequence<int>;
                        generateRandom(seq, seq_length, maxValue);
                        sort_name = "listShellSort";
                        exportTXT(seq, cmp, sort_name);
                        cout << "Please, check file sorts/" +  sort_name + ".txt" << endl;
                        break;
                }
                break;
            }
            cout << endl << "Stay of leave the program? (1, 2)" << endl;
            cout << "Select: ";
            closing = question(2);
        if (closing == 2) cout << "Bye!" << endl;

    } while (closing == 1);

    return 0;
}
