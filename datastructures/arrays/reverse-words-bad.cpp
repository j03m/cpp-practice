#include <iostream>
#include <string>
using namespace std;


string reverseWords(const string str) {

    int seeker = 0;
    int wordStart = 0;
    int len = str.length();
    int nextCopyPos = len;
    int lastWordLen = 0;
    string reversed(len, '-');
    while(seeker != str.length()+1){
        cout << "seeker: " << str[seeker] << "(" << seeker  << ") vs " << "(" << len << ") " << " wordStart: " << str[wordStart] << " lastWordLen: " << lastWordLen << "\n";
        if (str[seeker] == ' ' || seeker == len){
            int i = 0;
            while (wordStart <= seeker){
                reversed[(nextCopyPos - lastWordLen) + i] = str[wordStart];
                cout << "    moved wordStart: " << str[wordStart] << " to: " << (nextCopyPos - lastWordLen) + i << " str is:" << reversed << "\n";

                i++;
                wordStart++;
            }
            nextCopyPos = nextCopyPos - lastWordLen;
            lastWordLen = 0;
        }
        seeker++;
        lastWordLen++;
    }
    return reversed;
}

//[          steal]
//[steal pound cake]
//start: 11 end: 5
//len: 15   (15 - (11 - 5)
int main(){
   const string foo = reverseWords("steal pound cake");
   cout << "final:\n" <<  foo << "\n";

}