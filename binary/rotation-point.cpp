#include <vector>
#include <iostream>
#include<stdexcept>

using namespace std;

int findRotation(const vector<string> &words){
    if (words.size()<2){
        throw invalid_argument("need 2");
    }

    int floor = 0;
    int ceiling = words.size() - 1;

    const string first = words[0];
    while(floor < ceiling){
        int current = floor + ((ceiling - floor) / 2);

        //if the first letter of the previous word is > then the first letter of current word
        if (current > 0 && words[current-1] > words[current]){
            return current;
        }
        else if(words[current] < first){ //rotation is to our left
            ceiling = current;
        }
        else {
            floor = current;
        }
    }
    throw "nope";
}

int main () {
    const vector<string> words {
        "ptolemaic",
        "retrograde",
        "supplant",
        "undulate",
        "xenoepist",
        "asymptote",  // <-- rotates here!
        "babka",
        "banoffee",
        "engender",
        "karpatka",
        "othellolagkage",
    };

    const vector<string> letters { "k","v","a","b","c","d","e","g","i" };
    cout << findRotation(letters) << "\n";
}