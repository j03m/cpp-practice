#include<iostream>


void inc(int &foo){
    foo++;
}

void inc2(int foo){
    foo++;
}

void boolz(bool[] &bools){
    bools[0] = true;
    bools[1] = true;
}

int main(){
    int foo = 0;
    inc(foo);
    std::cout << foo << "\n";
    inc2(foo);
    std::cout << foo << "\n";

    bool bools[2];
    bools[0] = false;
    bools[1] = false;
    boolz(bools);
    std::cout << bools[0] << " " << bools[1];

}