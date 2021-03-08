#include<stack>
#include<iostream>
using namespace std;

struct ParenLocation {
    int start;
    int end;
};

ParenLocation detectParensWithStack(const string case1){
    stack<char> parens;
    auto location = ParenLocation { -1, -1 };
    int position = 0;
    for (char const &c: case1) {
        cout << " -> " << c << "\n";
        if (c == '('){
            if (parens.empty()){
                cout << " ---> start " << "\n";
                location.start = position;
            }
            parens.push(c);
        }
        if (c == ')' && !parens.empty()){
            parens.pop();
            if (parens.empty()){
                cout << " ---> end " << "\n";
                location.end = position;
            }
        }
        position++;
    }
    return location;
}


ParenLocation detectParens(const string case1){
    int parens = 0;
    auto location = ParenLocation { -1, -1 };
    int position = 0;
    for (char const &c: case1) {
        cout << " -> " << c << "\n";
        if (c == '('){
            if (parens == 0 && location.start == -1){
                cout << " ---> start " << "\n";
                location.start = position;
            }
            parens++;
        }
        else if (c == ')'){
            parens--;
            if (parens < 0){
                cout << "unbalanced end!" << "\n";
                return location;
            }
            if (parens == 0) {
                cout << " ---> end " << "\n";
                location.end = position;
                return location;
            }
        }
        position++;
    }
     cout << " UNBLANCED or NONE? " << "\n";
    return location;
}

void test(int num, const string testCase){
    cout << "case: " << num << "\n";
    auto location = detectParens(testCase);
    cout << "start: " << location.start << " end: " << location.end << "\n";
}

int main(){
    const string case1 = "Let's match (all of (these parens))";
    const string case2 = "()";
    const string case3 = "(()))";
//    test(1, case3);
//    test(2, case2);
//    test(3, case3);
//    test(4, "(");
//    test(5, ")");
    test(6, "))))))()");
//    test(6, "");


}