#include<iostream>
#include<string>
#include<stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<char, char> openersToClosers {
    make_pair('(', ')'),
    make_pair('[', ']'),
    make_pair('{', '}')
};

unordered_set<char> closers {
    ')', ']', '}'
};

bool checkBrackets(string input){
    int bracketChecks [3] = { 0, 0, 0 };
    for (const char &c: input){
        switch(c){
            case '{':
                bracketChecks[0]++;
                break;
            case '}':
                bracketChecks[0]--;
                break;
            case '[':
                bracketChecks[1]++;
                break;
            case ']':
                bracketChecks[1]--;
                break;
            case '(':
                bracketChecks[2]++;
                break;
            case ')':
                bracketChecks[2]--;
                break;
        }
    }

    bool wellFormed = true;
    for(int i:bracketChecks){
        wellFormed = wellFormed && i == 0;
    }
    return wellFormed;
}

bool isOpener(const char c){
    return c == '{' || c == '(' || c == '[';
}

bool isOpenerA(const char c){
    return openersToClosers.find(c) != openersToClosers.end();
}


bool isCloser(const char c){
    return c == '}' || c == ')' || c == ']';
}

bool isCloserA(const char c){
    return closers.find(c) != closers.end();
}

bool isMatch(stack<char> parens, const char c){
    if (parens.empty()){
        cout << "empty\n";
        return false;
    }

    const char top = parens.top();
    if (c == '}' && top == '{'){
        cout << "match}\n";
        return true;
    }
    if (c == ')' && top == '('){
        cout << "match)\n";
        return true;
    }
    if (c == ']' && top == '['){
        cout << "match]\n";
        return true;
    }
    return false;
}

bool isMatchA(stack<char> parens, const char c){
    if (parens.empty()){
        cout << "empty\n";
        return false;
    }

    const char top = parens.top();
    return openersToClosers[top] == c;
}

//j03m again but with MAP and SET
bool checkCorrectBrackets(string input){
    stack<char> parens;
    cout << "go\n";
    for (const char &c: input){
        cout << c;
        if (isOpener(c)){
            parens.push(c);
        }
        else if(isCloser(c)){
            if (!isMatch(parens, c)){
                return false;
            }
            parens.pop();
        }
    }

    return true;
}

bool checkCorrectBracketsForAdults(string input){
    stack<char> parens;
    cout << "go\n";
    for (const char &c: input){
        cout << c;
        if (isOpenerA(c)){
            parens.push(c);
        }
        else if(isCloserA(c)){
            if (!isMatchA(parens, c)){
                return false;
            }
            parens.pop();
        }
    }

    return true;
}

int main(){

    //j03m again but with MAP and SET
    string case1 = "{{sdsd[sdsdsd](sdsds)}}";
    string case2 = "{ [ ( ] ) }";
    string case3 = "{ [ }";
    string case4 = "}";
    cout << checkCorrectBrackets(case4) << "\n";
}

//https://www.interviewcake.com/question/cpp/bracket-validator?course=fc1&section=queues-stacks