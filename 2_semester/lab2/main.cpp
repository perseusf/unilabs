#include <iostream>
#include "src/vector.h"
#include "src/vector.cpp"
#include <complex>
#include <cmath>
#include <ctime>
using namespace std;

int setInt() {
    int a;
    cin >> a;
    return a;
}
double setDouble() {
    double a;
    cin >> a;
    return a;
}
complex<int> setComplex() {
    double Re, Im;
    cout << "Re = ";
    cin >> Re;
    cout << "Im = ";
    cin >> Im;
    return (complex<int> (Re, Im));
}
int setDim() {
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
Vector<int> createIntVector(int option, int dim){
    Vector<int> vector(dim);
    if (option == 1) {
        for (int i = 0; i < dim; ++i) {
            int a = rand() % 100 - 10;
            vector.Set(i, a);
        }
    }
    if (option == 2) {
        for (int i = 0; i < dim; ++i) {
            int a = setInt();
            vector.Set(i, a);
        }
    }
    return vector;
}
Vector<double> createFloatVector(int option, int dim){
    Vector<double> vector(dim);
    if (option == 1) {
        for (int i = 0; i < dim; ++i) {
            int b = (rand() % 10);
            double a = (rand()%100-1)*sqrt(b);
            vector.Set(i, a);
        }
    }
    if (option == 2) {
        for (int i = 0; i < dim; ++i) {
            double a = setDouble();
            vector.Set(i, a);
        }
    }
    return vector;
}
Vector<complex<int>> createComplexVector(int option, int dim){
    Vector<complex<int>> vector(dim);
    if (option == 1) {
        for (int i = 0; i < dim; ++i) {
            complex<int> a(rand()%100-10, rand()%100-10);
            vector.Set(i, a);
        }
    }
    if (option == 2) {
        for (int i = 0; i < dim; ++i) {
            complex<int> a = setComplex();
            vector.Set(i, a);
        }
    }
    return vector;
}

int main() {
    srand(time(nullptr));
    int type, operation, input, closing, dim;
    do {
        cout << "Integers, floats or complex numbers? (1, 2, 3)" << endl;
        cout << "Select: ";
        type = question(3);

        cout << endl <<"Addition, scalar multiplication, dot product or norm? (1, 2, 3, 4)" << endl;
        cout << "Select: ";
        operation = question(4);

        cout << endl << "Random or manually? (1, 2)" << endl;
        cout << "Select: ";
        input = question(2);

        cout << endl << "Enter dimension (length): ";
        dim = setDim();

        switch(operation) {
            case 1:
                if (type == 1) {
                    Vector<int> Vector1 = createIntVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<int> Vector2 = createIntVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "Vector1+Vector2 = " << Vector1.Addition(Vector2) << endl;
                }
                if (type == 2) {
                    Vector<double> Vector1 = createFloatVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<double> Vector2 = createFloatVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "Vector1+Vector2 = " << Vector1.Addition(Vector2) << endl;
                }
                if (type == 3) {
                    Vector<complex<int>> Vector1 = createComplexVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<complex<int>> Vector2 = createComplexVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "Vector1+Vector2 = " << Vector1.Addition(Vector2) << endl;
                }
                break;

            case 2:
                if (type == 1) {
                    Vector<int> Vector1 = createIntVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    int num;
                    cout << endl << "Enter a number: ";
                    num = setInt();
                    cout << num << "*Vector1 = " << Vector1.ScalarMultiplication(num) << endl << endl;
                }
                if (type == 2) {
                    Vector<double> Vector1 = createFloatVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    double num;
                    cout << endl << "Enter a number: ";
                    num = setDouble();
                    cout << num << "*Vector1 = " << Vector1.ScalarMultiplication(num) << endl << endl;
                    }
                if (type == 3) {
                    Vector<complex<int>> Vector1 = createComplexVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    complex<int> num;
                    cout << endl << "Enter a number: ";
                    num = setComplex();
                    cout << num << "*Vector1 = " << Vector1.ScalarMultiplication(num) << endl << endl;
                }
                break;

            case 3:
                if (type == 1) {
                    Vector<int> Vector1 = createIntVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<int> Vector2 = createIntVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "(Vector1, Vector2) = " << Vector1.DotProduct(Vector2) << endl << endl;
                }
                if (type == 2) {
                    Vector<double> Vector1 = createFloatVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<double> Vector2 = createFloatVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "(Vector1, Vector2) = " << Vector1.DotProduct(Vector2) << endl << endl;
                }
                if (type == 3) {
                    Vector<complex<int>> Vector1 = createComplexVector(input, dim);
                    cout << "Vector1" << " = " << Vector1 << endl << endl;
                    Vector<complex<int>> Vector2 = createComplexVector(input, dim);
                    cout << "Vector2" << " = " << Vector2 << endl << endl;
                    cout << "У меня не получилось скалярное произведение для комплексных (ответ не тот)" <<endl;
                    cout << "(Vector1, Vector2) = " << Vector1.DotProduct(Vector2) << endl << endl;
                }
                break;

            case 4:
                if (type == 1) {
                    Vector<int> Vector = createIntVector(input, dim);
                    cout << "Vector1" << " = " << Vector << endl << endl;
                    cout << "Norm(Vector1) = " << Vector.Norm() << endl << endl;
                }
                if (type == 2) {
                    Vector<double> Vector = createFloatVector(input, dim);
                    cout << "Vector1" << " = " << Vector << endl << endl;
                    cout << "Norm(Vector1) = " << Vector.Norm() << endl << endl;
                }
                if (type == 3) {
                    Vector<complex<int>> Vector = createComplexVector(input, dim);
                    cout << "Vector1" << " = " << Vector << endl << endl;
                    cout << "У меня не получилось высчитать норму для комплексных (ответ не тот)" <<endl;
                    cout << "Norm(Vector1) = " << Vector.Norm() << endl << endl;
                }
                break;
            }
            cout << endl << "Stay of leave the program? (1, 2)" << endl;
            cout << "Select: ";
            closing = question(2);
        if (closing == 2) printf("Bye!");
    } while(closing == 1);

    return 0;
}
