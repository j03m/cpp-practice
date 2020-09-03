#include <iostream>
#include <vector>
#include <map>


bool verifyOrders(const vector<int> &takeOut, const vector<int> &dineIn, const vector<int> &served){
    //1 pass - build dictionary of positions o(n) time space

    //scan each register make sure registered position increases in order

    //1: 1, 3: 5, 5: 4] - fail
    //1: 1, 3: 5, 5: 6] - pass


}

bool case1(){
    vector<int> takeOut { 1, 3, 5 };
    vector<int> dineIn { 2, 4, 6 };
    vector<int> served { 1, 2, 4, 6, 5, 4 };
    return verifyOrder(takeOut, dineIn, served)
}

bool case2(){
    vector<int> takeOut { 17, 8, 24 };
    vector<int> dineIn { 12, 19, 2 };
    vector<int> served { 17, 8, 12, 19, 24, 2 };
    return verifyOrder(takeOut, dineIn, served)
}


int main(){
    cout << case1(); << "\n";
    cout << case2(); << "\n";
}