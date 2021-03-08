#include<stack>
#include<iostream>
using namespace std;

class DuoStackQueue {

    private:
        stack<int> inStack;
        stack<int> outStack;
        int _dequeue(){
            int item = outStack.top();
            outStack.pop();
            return item;
        }

    public:
        void enqueue(int item){
            inStack.push(item);
        }

        int dequeue(){
            if (outStack.empty()){
                while(!inStack.empty()){
                    outStack.push(inStack.top());
                    inStack.pop();
                }
                if (outStack.empty()){
                    throw new runtime_error("empty queue");
                }

            }
            return _dequeue();
        }
};



int main(){

    DuoStackQueue dsq;
    dsq.enqueue(1);
    dsq.enqueue(2);
    dsq.enqueue(3);
    cout << dsq.dequeue() << "\n";
    cout << dsq.dequeue() << "\n";
    cout << dsq.dequeue() << "\n";
    return 0;
}