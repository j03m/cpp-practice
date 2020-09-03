
#include <iostream>
#include <string>
using namespace std;
void reverse(char * reverseMe){
    int len = strlen(reverseMe) -1;
    cout << "len: " << len<< "\n";
    int front = 0;
    int back = len;

    while(front <= back){
        char hold = reverseMe[front];
        cout << "hold: " << hold << "\n";
        reverseMe[front] = reverseMe[back];
        reverseMe[back] = hold;
        front++;
        back--;
        cout << "reverseMe: " << reverseMe << "\n";
        cout << "Front:" << front << " Back:" << back << "\n";
    }
}

int main(){
    char reverseMe[] = "hello world. Reverse me pls.";
    cout << reverseMe << "\n";
    reverse(reverseMe);

    cout << "Done: " << reverseMe << "\n";
}