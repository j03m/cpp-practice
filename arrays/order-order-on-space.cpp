#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool verifyQueue(const map<int,int> &orderPosition, const vector<int> queue){
    int lastPosition = -1;
    for(int orderId: queue){

        if ( orderPosition.find(orderId) == orderPosition.end() ) {
            return false; //never served, so therefore bad
        }

        int position = orderPosition.at(orderId);
        if (lastPosition!= -1 && position < lastPosition){
            return false;
        }
        lastPosition = position;
    }
    return true;
}

bool verifyOrders(const vector<int> &takeOut, const vector<int> &dineIn, const vector<int> &served){
    //1 pass - build dictionary of positions o(n) time space
    int position = 0;
    map<int, int> orderPosition;
    for(int orderId : served){
        cout << "id:" << orderId << " pos:" << position << "\n";
        orderPosition.insert(make_pair(orderId,position));
        position++;
    }

    return verifyQueue(orderPosition, takeOut) && verifyQueue(orderPosition, dineIn);

}

bool case1(){
    vector<int> takeOut { 1, 3, 5 };
    vector<int> dineIn { 2, 4, 6 };
    vector<int> served { 1, 2, 4, 6, 5, 3 };
    return verifyOrders(takeOut, dineIn, served);
}

bool case2(){
    vector<int> takeOut { 17, 8, 24 };
    vector<int> dineIn { 12, 19, 2 };
    vector<int> served { 17, 8, 12, 19, 24, 2 };
    return verifyOrders(takeOut, dineIn, served);
}

bool case3(){
    vector<int> takeOut { 17, 8, 24 };
    vector<int> dineIn { 12, 19, 2 };
    vector<int> served { 17, 8, 12, 24, 2 };
    return verifyOrders(takeOut, dineIn, served);
}


int main(){
    cout << case1() << "\n";
    cout << case2() << "\n";
    cout << case3() << "\n";
}