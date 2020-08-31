//https://www.interviewcake.com/question/cpp/product-of-other-numbers

//We can do this in o(n)
//https://www.interviewcake.com/question/cpp/product-of-other-numbers
#include<iostream>
using namespace std;

void show(int results[], int len){
    cout << "result: [";
    for(int i = 0; i < len; i++){
         cout << results[i] << " ";
    }
    cout << "]" << "\n";
}

int main()
{
    const int numbers[] = {1, 7, 3, 4};
    int len = sizeof(numbers)/sizeof(numbers[0]);
    int results[len];
    int current = 1;
    for(int i = 0; i < len; i++){
        results[i] = current;
        current *= numbers[i];
    }

    show(results, len);

    current = 1;
    for(int i = len; i > 0; i--){
        int j = i - 1;
        results[j] *= current;
        current *= numbers[j];
    }

    show(results, len);
}
