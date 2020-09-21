#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;



int main(){


    //1, 7, 3, 4
    //before: 1, 7, 21, 44
    //after: 1, 4, 12, 84
    vector<int> numbers {1, 7, 3, 4};
    vector<int> answers(numbers.size());

    int soFar = 1;
    for(int i = 0; i<numbers.size(); i++){
        answers[i] = soFar;
        soFar *= numbers[i];
    }
    soFar = 1;
    for (int i = numbers.size() - 1; i >= 0; i--){
        answers[i] *= soFar;
        soFar *= numbers[i];
    }

    for(int i = 0; i<numbers.size(); i++){
        cout << answers[i] << "\n";
    }

}