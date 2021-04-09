/**
Goal:

Generic type
Generic comparator
Dynamic resizing
**/
#include <iostream>
#include <stdexcept>


template <class T>
class BinHeap {

    private:
        T *heapStorage;
        int heapSize;
        void decreaseKey(T value);
        std::function<bool(T,T)> _predicate;

    public:
        BinHeap(std::function<bool(T,T)> predicate);
};