#include <iostream>
#include "src/heap.h"
#include "src/heap.cpp"
#include "src/set.h"
#include "src/set.cpp"
#include "src/functions.h"
#include <ctime>
using namespace std;
#define MAX 10000

int main() {
    srand(time(NULL));
    int type, input, closing, size, container, operationheap, operationset, timetests;
    do {
        cout << "Heap or set? (1, 2)" << endl;
        cout << "Select: ";
        container = enterChoice(2);

        cout << "Ints or doubles? (1, 2)" << endl;
        cout << "Select: ";
        type = enterChoice(2);

        cout << "Run timetests? Yes, no? (1, 2)" << endl;
        cout << "Select: ";
        timetests = enterChoice(2);

        if (timetests == 1) {
            cout << "RUNNING TIME TESTS FOR SETS" << endl;
            cout << "UNION, COMPLEMENT, INTERSECTION." << endl;

            for (int i = 1; i < MAX; i += 1000) {
                cout << "Number of elements: " << i << endl;
                testIntUnionSet(i);
            }
            cout << endl << endl << endl;
            for (int i = 1; i < MAX; i += 1000) {
                cout << "Number of elements: " << i << endl;
                testIntComplementSet(i);
            }
            cout << endl << endl << endl;
            for (int i = 1; i < MAX; i += 1000) {
                cout << "Number of elements: " << i << endl;
                testIntIntersectionSet(i);
            }
        }

        //heap
        if (container == 1) {
            cout << endl << "Random or manually? (1, 2)" << endl;
            cout << "Select: ";
            input = enterChoice(2);

            //random
            if (input == 1) {
                cout << "Enter size: ";
                cin >> size;
                if (type == 1) {
                    Heap<int> intheap = randomIntHeap(size);
                    cout << intheap << endl;
                    do {
                        cout << endl
                             << "Add an element, Delete an element, Search for an element, Make a subheap, Done? (1, 2, 3, 4, 5)"
                             << endl;
                        cout << "Select: ";
                        operationheap = enterChoice(5);
                        switch (operationheap) {
                            case 1: {
                                int element;
                                cout << "Enter the value: ";
                                cin >> element;
                                intheap.insert(element);
                                cout << intheap << endl;
                                }
                                break;
                            case 2:
                                {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl;
                                    break;
                                }
                                int index;
                                cout << "Enter the value to delete: ";
                                index = enterIndex();
                                    intheap.DeleteByValue(intheap.GetElemByIndex(index));
                                cout << intheap << endl;
                                }
                                break;
                            case 3:
                                {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl;
                                    break;
                                }
                                int element;
                                cout << "Enter the value to find an index: ";
                                cin >> element;
                                int item = intheap.GetIndexByElem(element);
                                if (item != -1)
                                    cout << "Value's index: " << intheap.GetIndexByElem(element) << endl;
                                if (item == -1)
                                    cout << "The value is not found" << endl;
                                }
                                break;
                            case 4:
                                {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl;
                                    break;
                                }
                                int item;
                                cout << "Enter index of the root of a subheap: ";
                                    item = enterIndex();
                                cout << *intheap.GetSubHeap(item) << endl << endl;
                                }
                                break;
                        }
                    } while (operationheap != 5);
                }
                if (type == 2) {
                    Heap<double> heap_double = randomDoubleHeap(size);
                    cout << heap_double << endl << endl;
                    do {
                        cout << endl
                             << "Add a value, Delete a value, Search for a value, Make a subheap, Done? (1, 2, 3, 4, 5)"
                             << endl;
                        cout << "Select: ";
                        operationheap = enterChoice(5);
                        switch (operationheap) {
                            case 1:
                                {
                                cout << "Enter a value: ";
                                double element;
                                cin >> element;
                                heap_double.insert(element);
                                cout << heap_double << endl << endl;
                                }
                                break;
                            case 2:
                                {
                                if (!heap_double.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                int index;
                                cout << "Enter an index of the value to delete: ";
                                index = enterIndex();
                                    heap_double.DeleteByValue(heap_double.GetElemByIndex(index));
                                cout << heap_double << endl << endl;
                                }
                                break;
                            case 3:
                                {
                                if (!heap_double.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                double element;
                                cout << "Enter the value to find an index: ";
                                cin >> element;
                                int item = heap_double.GetIndexByElem(element);
                                if (item != -1)
                                    cout << "Value's index: " << heap_double.GetIndexByElem(element) << endl << endl;
                                if (item == -1)
                                    cout << "The value is not found" << endl << endl;
                                }
                                break;
                            case 4:
                                {
                                if (!heap_double.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                int item;
                                cout << "Enter index of a root of a subheap: ";
                                item = enterIndex();
                                cout << *heap_double.GetSubHeap(item) << endl << endl;
                                }
                                break;
                        }
                    } while (operationheap != 5);
                }
            }

            //keyboard
            if (input == 2) {
                cout << "Enter size: ";
                cin >> size;
                if (type == 1) {
                    Heap<int> intheap = keyboardIntHeap(size);
                    cout << intheap << endl << endl;
                    do {
                        cout << endl
                             << "Add a value, Delete a value, Search for a value, Make a subheap, Done? (1, 2, 3, 4, 5)"
                             << endl;
                        cout << "Select: ";
                        operationheap = enterChoice(5);
                        switch (operationheap) {
                            case 1: {
                                int element;
                                cout << "Enter a value: ";
                                cin >> element;
                                intheap.insert(element);
                                cout << intheap << endl << endl;
                            }
                            break;
                            case 2: {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                int index;
                                cout << "Enter an index of the value to delete: ";
                                index = enterIndex();
                                intheap.DeleteByValue(intheap.GetElemByIndex(index));
                                cout << intheap << endl << endl;
                            }
                            break;
                            case 3: {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                int element;
                                cout << "Enter a value to find an index: ";
                                cin >> element;
                                int item = intheap.GetIndexByElem(element);
                                if (item != -1)
                                    cout << "Value's index: " << intheap.GetIndexByElem(element) << endl << endl;
                                if (item == -1)
                                    cout << "Value is not found" << endl << endl;
                            }
                            break;
                            case 4: {
                                if (!intheap.GetLength()) {
                                    cout << "The heap is empty" << endl << endl;
                                    break;
                                }
                                int index_sub;
                                cout << "Enter an index of a root of a subheap: ";
                                index_sub = enterIndex();
                                cout << *intheap.GetSubHeap(index_sub) << endl << endl;
                            }
                            break;
                        }
                    } while (operationheap != 5);
                }
                if (type == 2) {
                    Heap<double> doubleheap = keyboardDoubleHeap(size);
                    cout << doubleheap << endl << endl;

                    do {
                        cout << endl
                             << "Add a value, Delete a value, Search for a value, Make a subheap, Done? (1, 2, 3, 4, 5)"
                             << endl;
                        cout << "Select: ";
                        operationheap = enterChoice(5);
                        switch (operationheap) {
                            case 1:
                                {
                                    double element;
                                    cout << "Enter a value: ";
                                    cin >> element;
                                    doubleheap.insert(element);
                                    cout << doubleheap << endl << endl;
                                }
                                break;
                            case 2:
                                {
                                    if (!doubleheap.GetLength()) {
                                        cout << "The heap is empty" << endl << endl;
                                        break;
                                    }
                                    int index;
                                    cout << "Enter an index of a value to delete: ";
                                    index = enterIndex();
                                    doubleheap.DeleteByValue(doubleheap.GetElemByIndex(index));
                                    cout << doubleheap << endl << endl;
                                }
                                break;
                            case 3:
                                {
                                    if (!doubleheap.GetLength()) {
                                        cout << "The heap is empty" << endl << endl;
                                        break;
                                    }
                                    double element;
                                    cout << "Enter a value to find an index: ";
                                    cin >> element;
                                    int item = doubleheap.GetIndexByElem(element);
                                    if (item != -1)
                                        cout << "Value's index: " << doubleheap.GetIndexByElem(element) << endl << endl;
                                    if (item == -1) cout << "Value is not found" << endl << endl;
                                }
                                break;
                            case 4:
                                {
                                    if (!doubleheap.GetLength()) {
                                        cout << "The heap is empty" << endl << endl;
                                        break;
                                    }
                                    int item;
                                    cout << "Enter an index of a root of a subheap: ";
                                    item = enterIndex();
                                    cout << *doubleheap.GetSubHeap(item) << endl << endl;
                                }
                                break;
                        }
                    } while (operationheap != 5);
                }
            }
        }

        //set
        if (container == 2) {
            cout << endl << "Random or manually? (1, 2)" << endl;
            cout << "Select: ";
            input = enterChoice(2);

            //random
            if (input == 1) {
                cout << "Enter a size of a set: ";
                size = enterSize();
                if (type == 1) {
                    Set<int> intset1 = randomIntSet(size);
                    cout << "A = " << intset1 << endl << endl;
                    Set<int> intset2 = randomIntSet(size);
                    cout << "B = " << intset2 << endl << endl;

                    //UNION
                    cout << "UNION:" << endl;
                    cout << "A union B = " << intset1 + intset2 << endl << endl;

                    //COMPLEMENT
                    cout << "COMPLEMENT:" << endl;
                    cout << "A complement B = " << intset1 - intset2 << endl << endl;

                    //INTERSECTION
                    cout << "INTERSECTION:" << endl;
                    cout << "A intersect B = " << intset1 * intset2 << endl << endl;

                    //CHECK EQUALITY
                    cout << "CHECK EQUALITY:" << endl;
                    if (intset1 == intset2) cout << "B is equal to A" << endl << endl;
                    else cout << "B is not equal to A" << endl << endl;
                }
                if (type == 2) {
                    Set<double> doubleset1 = randomDoubleSet(size);
                    cout << "A = " << doubleset1 << endl << endl;
                    srand(time(NULL));
                    Set<double> doubleset2 = randomDoubleSet(size);
                    cout << "B = " << doubleset2 << endl << endl;

                    //UNION
                    cout << "UNION:" << endl;
                    cout << "A + B = " << doubleset1 + doubleset2 << endl << endl;

                    //COMPLEMENT
                    cout << "COMPLEMENT:" << endl;
                    cout << "A - B = " << doubleset1 - doubleset2 << endl << endl;

                    //INTERSECTION
                    cout << "INTERSECTION:" << endl;
                    cout << "A * B = " << doubleset1 * doubleset2 << endl << endl;

                    //CHECK EQUALITY
                    cout << "CHECK EQUALITY:" << endl;
                    if (doubleset1 == doubleset2) cout << "B is equal to A" << endl << endl;
                    else cout << "B is not equal to A" << endl << endl;
                }
            }

            //keyboard
            if (input == 2) {
                cout << "Enter size of a heap: ";
                cin >> size;
                if (type == 1) {
                    Set<int> intset1 = keyboardIntSet(size);
                    cout << "A = " << intset1 << endl << endl;
                    Set<int> intset2 = keyboardIntSet(size);
                    cout << "B = " << intset2 << endl << endl;

                    //UNION
                    cout << "UNION:" << endl;
                    cout << "A + B = " << intset1 + intset2 << endl << endl;

                    //COMPLEMENT
                    cout << "COMPLEMENT:" << endl;
                    cout << "A - B = " << intset1 - intset2 << endl << endl;

                    //INTERSECTION
                    cout << "INTERSECTION:" << endl;
                    cout << "A * B = " << intset1 * intset2 << endl << endl;

                    //CHECK EQUALITY
                    cout << "CHECK EQUALITY:" << endl;
                    if (intset1 == intset2) cout << "B is equal to A" << endl << endl;
                    else cout << "B is not equal to A" << endl << endl;
                }
                if (type == 2) {
                    Set<double> doubleset1 = keyboardDoubleSet(size);
                    cout << "A = " << doubleset1 << endl << endl;
                    Set<double> doubleset2 = keyboardDoubleSet(size);
                    cout << "B = " << doubleset2 << endl << endl;

                    //UNION
                    cout << "UNION:" << endl;
                    cout << "A + B = " << doubleset1 + doubleset2 << endl << endl;

                    //COMPLEMENT
                    cout << "COMPLEMENT:" << endl;
                    cout << "A - B = " << doubleset1 - doubleset2 << endl << endl;

                    //INTERSECTION
                    cout << "INTERSECTION:" << endl;
                    cout << "A * B = " << doubleset1 * doubleset2 << endl << endl;

                    //CHECK EQUALITY
                    cout << "CHECK EQUALITY:" << endl;
                    if (doubleset1 == doubleset2) cout << "B is equal to A" << endl << endl;
                    else cout << "B is not equal to A" << endl << endl;
                }
            }

            Set<int> intset;
            Set<double> doubleset;

            do {
                cout << "Add a value, Delete a value, Search for a value, Done (1, 2, 3, 4)" << endl;
                cout << "Select: ";
                operationset = enterChoice(4);
                switch (operationset) {
                    case 1:
                        if (type == 1) {
                            cout << "Enter a value: ";
                            int element;
                            cin >> element;
                            intset.insert(element);
                            cout << intset << endl << endl;
                        }
                        if (type == 2) {
                            cout << "Enter a value: ";
                            double element;
                            cin >> element;
                            doubleset.insert(element);
                            cout << doubleset << endl << endl;
                        }
                        break;
                    case 2:
                        if (type == 1) {
                            if (!intset.GetSize()) {
                                cout << "The set is empty" << endl << endl;
                                break;
                            }
                            cout << "Enter the value to delete: ";
                            int element;
                            cin >> element;
                            intset.DeleteValue(element);
                            cout << intset << endl << endl;
                        }
                        if (type == 2) {
                            if (!doubleset.GetSize()) {
                                cout << "The heap is empty" << endl << endl;
                                break;
                            }
                            cout << "Enter the value to delete: ";
                            double element;
                            cin >> element;
                            doubleset.DeleteValue(element);
                            cout << doubleset << endl << endl;
                        }
                        break;
                    case 3:
                        if (type == 1) {
                            if (!intset.GetSize()) {
                                cout << "The heap is empty" << endl << endl;
                                break;
                            }
                            cout << "Enter the value to find an index: ";
                            int element;
                            cin >> element;
                            if (intset.Find(element))
                                cout << "The value is found" << endl << endl;
                            if (!intset.Find(element))
                                cout << "The value is not found" << endl << endl;
                        }
                        if (type == 2) {
                            if (!doubleset.GetSize()) {
                                cout << "The heap is empty" << endl << endl;
                                break;
                            }
                            cout << "Enter the value to find an index: ";
                            double element;
                            cin >> element;
                            if (doubleset.Find(element))
                                cout << "The value is found" << endl << endl;
                            if (!doubleset.Find(element))
                                cout << "The value is not found" << endl << endl;
                        }
                        break;
                }
            } while (operationset != 4);
        }
        cout << endl << "Stay of leave the program? (1, 2)" << endl;
        cout << "Select: ";
        closing = enterChoice(2);
        if (closing == 2)
            cout << "Bye!" << endl;
    } while (closing == 1);
    return 0;
}