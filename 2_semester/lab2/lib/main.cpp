#include <iostream>
#include "custom.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Custom<int>* temp = new Custom<int>(1);
    temp->bar();
    return 0;
}
