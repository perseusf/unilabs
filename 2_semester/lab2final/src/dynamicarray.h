#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


template<class T>
class DynamicArray {

private:
    T *data;
    int length;

public:
    //Constructors
    DynamicArray();
    DynamicArray(T *array, int size);
    DynamicArray(int length);
    DynamicArray(const DynamicArray<T>& array);

    //Decomposition
    T& Get(int index);
    void DelByIndex(int index);
    int GetLength() const;

    //Operations
    void Set(int index, const T &value);
    void Resize(int length);
    T& operator[](const int index);
    bool operator==(const DynamicArray<T> &array);

    //Destructor
    ~DynamicArray();
};

#endif // DYNAMICARRAY_H
