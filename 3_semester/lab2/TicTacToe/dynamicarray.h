#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


template <typename T>
class DynamicArray {
private:
    T *data_;
    int length_;
public:
    //constructors
    DynamicArray();
    DynamicArray(T *array, int size);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T> &array);

    //decomposition
    T& Get(int index);
    void DelByIndex(int index);
    int GetLength() const;

    //operations
    void Set(int index, const T &value);
    void Resize(int length);

    //operators
    T& operator[](const int index);
    bool operator==(const DynamicArray<T> &array);

    //destructor
    ~DynamicArray();
};

#endif // DYNAMICARRAY_H
