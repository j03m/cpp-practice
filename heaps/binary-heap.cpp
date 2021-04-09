#include <iostream>
#include <stdexcept>
#include "./binary-heap.h"
using namespace std;


bool compare(int c1, int c2){
    return c1 > c2;
}


template <class T>
BinHeap<T>::BinHeap(std::function<bool(T,T)>  predicate):_predicate(predicate){

}


int main(){
    BinHeap<int> h(compare);
}