#include <stack>
#include<iostream>
using namespace std;

class MyQueue {
    stack<int> stack1, stack2;

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;  
    cout << q.pop() << endl;   
    cout << (q.empty() ? "true" : "false") << endl;  
    return 0;
}