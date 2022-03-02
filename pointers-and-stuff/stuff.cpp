#include<iostream>
#include<stack>

using namespace std;

void access(stack<int> &st){
    //reference via .
    st.push(1);
}

void accessP(stack<int> *st){
    st->push(2);
}


void accessC(stack<int> st){
    //reference via .
    st.push(3);
}


int main() {

    stack<int> st;

    access(st);

    accessP(&st);

    accessC(st);

    stack<int> * sp = &st;
    access(*sp);

    accessP(sp);

    cout << st.top() << "\n";

    int *i;
    *i = 10;

    cout << i << "\n";
    cout << *i << "\n";

}