#include <functional>
#include <iostream>
using namespace std;
using namespace std::placeholders;

void f(int one, int two, int three){
    std::cout << " one:" << one << " two: " << two << " three: " << three << "\n";
}


int main(){
    auto bound = std::bind(f,  _1, 1, _2);
    bound(2 ,3);
}