#include <iostream>
#include <string>
using namespace std;
void flipString(string &input, int start, int end){
    //check edge cases

    //o(n) reverse letters
    while(start <= end){
        char temp = input[end];
        input[end] = input[start];
        input[start] = temp;
        start++;
        end--;
    }
}

void reverseWords(string &input){
    //check edge cases
    cout << "input:" << input << "\n";
    flipString(input, 0, input.length()-1);
    cout << "flipped: " << input << "\n";
    int seeker = 0;
    int wordStart = 0;
    while(seeker <= input.length()){
        if (input[seeker] == ' ' || seeker == input.length()){
            int end = seeker - 1;
            flipString(input, wordStart, end);
            wordStart = seeker + 1;
        }
        seeker++;
    }
}

int main()
{
    string str = string("cake pound steal");
    cout << "len:" << str.length() << "\n";
    reverseWords(str);
    cout << str << "\n";
}