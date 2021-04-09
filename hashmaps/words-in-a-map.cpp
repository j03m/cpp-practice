#include <iostream>
#include <unordered_map>
#include <string>
#include <ctype.h>
using namespace std;

void track(unordered_map<string, int> &map, string value){
    auto entry = map.find(value);
    if (entry == map.end() ){
        map.insert(make_pair(value, 1));
    }
    else {
        entry->second++;
    }
}

unordered_map<string, int> parseMap(const string str)
{
    //scan for space or non word
    unordered_map<string, int> map;
    string currentToken = "";
    for (char c : str){
        // - is a special case we would need to add checking here
        // for - you need to check if the chars to left and right are
        // alpha, if so then capture the whole thing. As such you would need to
        // something index based rather than an interator
        if (isalpha(c) || c == '-' || c == '\'') {
            currentToken += std::tolower(c);
        }
        else {
            if (c != ' '){
                //add/inc c to map
                string nonWord(1, c);
                track(map, nonWord);
            }
            else if (currentToken != ""){
                //add/inc current to map, reset current token
                track(map, currentToken);
                currentToken = "";
            }
        }
    }
    return map;
}

void prettyPrintMap(unordered_map<string, int> map){
    for (std::pair<string, int> element : map)
    {
        std::cout << element.first << " :: " << element.second << std::endl;
    }
}

int main()
{
    string str1 = "After beating the eggs, Dana read the next step:";
    string str2 = "Add milk and egg-product, then add flour's and sugar.";
    prettyPrintMap(parseMap(str1));
    //iterate keys/counts
    cout << "******" << std::endl;
    prettyPrintMap(parseMap(str2));

    //iterate keys/counts
}