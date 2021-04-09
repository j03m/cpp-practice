/**
Goal:

Generic type
Generic comparator
Dynamic resizing
**/
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template <class T>
class BinHeap {

    private:
        vector<T> heapStorage;
        int heapSize;
        void decreaseKey(T value);
        std::function<bool(T,T)> _predicate;
        void swap(int pos1, int pos2);
        void decreaseKey();
        int parent(int position);
        int left(int position);
        int right(int position);
        void heapify(int position);

    public:
        BinHeap(std::function<bool(T,T)> predicate);
        BinHeap(vector<T> data, std::function<bool(T,T)> predicate);
        void insert(T element);
        T peekHead();
        T popHead();

};