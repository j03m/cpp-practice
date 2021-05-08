#include "./binary-heap.h"
using namespace std;


bool compare(int c1, int c2){
    return c1 > c2;
}


template <class T>
BinHeap<T>::BinHeap(std::function<bool(T,T)>  predicate):_predicate(predicate){}

template <class T>
BinHeap<T>::BinHeap(vector<T> data, std::function<bool(T,T)>  predicate):
    _predicate(predicate),
    heapStorage(data){
    heapify(0);
}

template <class T>
void BinHeap<T>::insert(T element){
    heapStorage.push_back(element);
    decreaseKey();
}

template <class T>
int  BinHeap<T>::parent(int position){
     return ( position -1 ) / 2;
}

template <class T>
int BinHeap<T>::left(int position){
    return position * 2 + 1;
}

template <class T>
int BinHeap<T>::right(int position){
    return position * 2 + 2;
}

template <class T>
void BinHeap<T>::swap(int pos1, int pos2){
    T element = heapStorage[pos1];
    heapStorage[pos1] = heapStorage[pos2];
    heapStorage[pos2] = element;
}

template <class T>
void BinHeap<T>::heapify(int position){
    int leftPos = left(position);
    int rightPos = right(position);
    int size = heapStorage.size();
    int smallest = position;
    if (leftPos < size && _predicate(heapStorage[leftPos], heapStorage[position])){
        smallest = leftPos;
    }
    if (rightPos < size &&  _predicate(heapStorage[rightPos], heapStorage[position])){
        smallest = rightPos;
    }

    if (smallest != position){
        swap(position, smallest);
        heapify(smallest);
    }
}

template <class T>
void BinHeap<T>::decreaseKey(){
    //get the end of the vector
    //calculate the parent position
    //if the parent compares true swap them
    //todo: FIND THE BUG
    int pos = heapStorage.size() - 1;
    int parentPos = parent(pos);
    while(pos != 0 && _predicate(heapStorage[pos], heapStorage[parentPos])){
        swap(pos, parentPos);
        pos = parentPos;
        parentPos = parent(pos);
    }
}

template <class T>
T BinHeap<T>::peekHead(){
    return heapStorage[0];
}

template <class T>
T BinHeap<T>::popHead(){
    //capture the head and bottom
    T head = heapStorage[0];
    T back = heapStorage.back();

    //reduce the size of the vector and reheap
    heapStorage.pop_back();
    heapStorage[0] = back;

    heapify(0);

    return head;
}

int main(){
    BinHeap<int> h(compare);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.peekHead() << " pop: ";
    cout << h.popHead() << "  now: " << h.peekHead();
    return 0;
}
