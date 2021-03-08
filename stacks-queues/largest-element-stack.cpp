#include<stack>
#include<iostream>
using namespace std;

class MaxStack {

    private:
        stack<int> _data;
        stack<int> _maxes;
        int _pop(){
            const int top = _data.top();
            _data.pop();
            return top;
        }

    public:

    void push(int number){
        if (!_data.empty()){
            const int top = _data.top();
            if (number >= top){
                _maxes.push(number);
            }
        }
        else {
            _maxes.push(number);
        }
        _data.push(number);
    }

    int pop(){
        const int top = _pop();
        const int max = _maxes.top();
        if (top == max){
            _maxes.pop();
        }
        return top;
    }

    int getMax(){
        return _maxes.top();
    }
};


int main(){
    cout << "1\n";
    MaxStack maxStack;
    cout << "2\n";
    maxStack.push(3);
    cout << "3\n";

    maxStack.push(5);
    maxStack.push(3);
    maxStack.push(6);
    maxStack.push(1);

    //6,1
    cout << "max: " << maxStack.getMax() << "\n";
    cout << "pop:" << maxStack.pop() << "\n";

    //6,6
    cout << "max: " << maxStack.getMax() << "\n";
    cout << "pop" << maxStack.pop() << "\n";

    //5,3
    cout << "max: " << maxStack.getMax() << "\n";
    cout << "pop" << maxStack.pop() << "\n";

    //5,5
    cout << "max: " << maxStack.getMax() << "\n";
    cout << "pop" << maxStack.pop() << "\n";

    //3,3
    cout << "max: " << maxStack.getMax() << "\n";
    cout << "pop" << maxStack.pop() << "\n";

}