#include <iostream>
#include <deque>
#include <vector>
#include <map>
using namespace std;

bool verifyOrders(vector<int> &served, deque<int> &dineIn, deque<int> &takeOut){
    for (int orderId : served){
        if (dineIn.size() > 0 && orderId == dineIn[0]){
            dineIn.pop_front();
        }
        else if (takeOut.size() > 0 && orderId == takeOut[0]){
            takeOut.pop_front();
        }
        else {
            return false;
        }
    }

    if (dineIn.size() != 0 || takeOut.size() != 0) {
        return false;
    }

    return true;
}

bool case1(){
    deque<int> takeOut { 1, 3, 5 };
    deque<int> dineIn { 2, 4, 6 };
    vector<int> served { 1, 2, 4, 6, 5, 3 };
    return verifyOrders(served, dineIn, takeOut);
}

bool case2(){
    deque<int> takeOut { 17, 8, 24 };
    deque<int> dineIn { 12, 19, 2 };
    vector<int> served { 17, 8, 12, 19, 24, 2 };
    return verifyOrders(served, dineIn, takeOut);
}

bool case3(){
    deque<int> takeOut { 17, 8, 24 };
    deque<int> dineIn { 12, 19, 2 };
    vector<int> served { 17, 8, 12, 24, 2 };
    return verifyOrders(served, dineIn, takeOut);
}

int main(){
    cout << case1() << "\n";
    cout << case2() << "\n";
    cout << case3() << "\n";
}