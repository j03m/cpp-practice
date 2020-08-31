
#include<iostream>
using namespace std;
int main()
{
    const int numbers[] = {1, 7, 3, 4};
    int len = sizeof(numbers)/sizeof(numbers[0]);
    int results[len];
    for(int i = 0; i < len; i++){
        int current = 1;
        for(int ii = 0; ii < len; ii++){
            if (i == ii){
                continue;
            }
            current *= numbers[ii];
        }
        results[i] = current;
    }
    cout << "result: [";
    for(int i = 0; i < len; i++){
         cout << results[i] << " ";
    }
    cout << "]" << "\n";
}