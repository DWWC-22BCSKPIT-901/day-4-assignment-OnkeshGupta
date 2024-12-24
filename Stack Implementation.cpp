#include <iostream>
#define MAX 1000

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << " popped from stack\n";
    std::cout << "Top element is " << stack.peek() << "\n";
    std::cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << "\n";

    return 0;
}