#include<iostream>
#include<unordered_map>
using namespace std;

// recursive, 2^n does many calculations multiple times.
int fibR(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }
    return fibR(n - 1) + fibR(n - 2);
}


//memoize - faster then 2^n but bad on space. Uses N space in the map
//and N space on the stack
int fibM(int n, unordered_map<int,int> &cache)
{
    if (n == 0 || n == 1) {
        return n;
    }

    auto entry = cache.find(n);
    if (entry != cache.end() ){
        return entry->second;
    }

    int result = fibM(n-1, cache) + fibM(n-2, cache);
    cache.insert(make_pair(n, result));
    return result;
}


//Bottom up, calculate from 0 upward
int fib(int n){
    if (n < 0){
        throw invalid_argument("bad index");
    }
    else if(n == 0 || n == 1){
        return n;
    }

    int prevPrev = 0;
    int prev = 1;
    int current = 0;
    for (int i = 1; i<n; i++){
        current = prevPrev + prev;
        prevPrev = prev;
        prev = current;
    }
    return current;
}


int main(){

    unordered_map<int,int> cache;
    cout << "B:" << fibM(4, cache)  << "\n";

    cout << "R:" << fibR(4) << "\n";

    cout << "G:" << fib(4) << "\n";

}