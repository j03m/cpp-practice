#include<functional>
#include<iostream>
using namespace std;
using namespace std::placeholders;


int add(int a, int b){
    cout << " Adding: " << a << " + " << b << "\n";
    return a + b;
}

int main (){
    auto add1 = std::bind(&add, _1, 5);
    cout << add1(1, 2);
}