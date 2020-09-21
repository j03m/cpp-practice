#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>
using namespace::std;


//works but omg way over done
bool hasPalindromeUgh(const string &str){
    if (str.length() == 1){
        return true;
    }

    struct MapEntry {
        int count;
        bool even;
    };

    map<char, MapEntry> charMap;
    cout << "***building map:" << "\n";
    for(const char &c : str){
        auto entry = charMap.find(c);
        if ( entry == charMap.end()) {
            MapEntry m;
            m.count = 1;
            m.even = false;
            charMap.insert(make_pair(c, m));
        }
        else {
            entry->second.count++;
            entry->second.even = entry->second.count % 2 == 0;
            cout << entry->first << ":" <<  entry->second.count << ":" << entry->second.even << "\n";
        }
    }

    int odds = 0;
    cout << "***characters:" << "\n";
    for (auto entry : charMap){;
        cout << entry.first << ":" << entry.second.count << "\n";
        if (!entry.second.even){
            odds++;
        }
        if (odds > 1){
            cout << "odd: " << entry.first << ":" << entry.second.even << "\n";
            return false;
        }
    }
    return true;
}

//very elegant
bool hasPalindrome(const string &str) {
    unordered_set<char> unpairedCharacters;
    for (char c : str){
        if (unpairedCharacters.find(c) != unpairedCharacters.end()){
            unpairedCharacters.erase(c);
        }
        else {
            unpairedCharacters.insert(c);
        }
    }
    return unpairedCharacters.size() <= 1;
}

int main(){

    bool a = hasPalindrome("ghghi");
    bool b = hasPalindrome("ghghii");
    bool c = hasPalindrome("ghghiii");
    bool d = hasPalindrome("ghghia");
    cout << "yes: " << a << " " << b << "\n";
    cout << "no: " << c << " " << d << "\n";

}