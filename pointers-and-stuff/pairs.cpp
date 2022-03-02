#include<iostream>
#include<utility>
#include<functional>
#include<string>
#include <chrono>
#include <fstream>
using namespace std;
using TimePoint = std::chrono::steady_clock::time_point;
using FileData = std::pair<std::ofstream, TimePoint>;
void takeReference(std::pair<std::string, int> &p){
    p = std::make_pair("bar", 3);
}

int main () {

    std::pair<std::string, int> p1;
    std::cout << ">" << p1.first << ":" << p1.second << "\n";
    p1 = std::make_pair("foo", 2);
    std::cout << ">" << p1.first << ":" << p1.second << "\n";
    takeReference(p1);
    std::cout << ">" << p1.first << ":" << p1.second << "\n";

    FileData p2;
    p2.first.open("./out.txt");


}