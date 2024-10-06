#include<iostream>
using namespace std;

class Stack {
public:
    int top;
    int* arr;
    int size;

    // Constructor to initialize the stack with a given size
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    // Push an element onto the stack
    void push(int element) {
        if (top == size - 1) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            arr[top] = element;
        }
    }

    // Pop the top element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack is empty, cannot pop!" << endl;
            return -1;
        } else {
            int popped = arr[top];
            top--;
            return popped;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Peek at the top element
    int peek() {
        if (top != -1) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

class Queue {
    Stack *stack1;
    Stack *stack2;
    int size;
public:
    Queue(int size) {
        stack1 = new Stack(size);
        stack2 = new Stack(size);
        this->size = size;
    }

    // Enqueue operation: push elements to stack1
    void enqueue(int value) {
        stack1->push(value);
        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue operation: pop from stack2 if not empty, otherwise transfer from stack1 to stack2
    int dequeue() {
        if (stack2->isEmpty()) {
            if (stack1->isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            while (!stack1->isEmpty()) {
                int temp = stack1->pop();
                stack2->push(temp);
            }
        }
        return stack2->pop();
    }

    // Check if queue is empty
    bool isEmpty() {
        return stack1->isEmpty() && stack2->isEmpty();
    }
};

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << " dequeued from queue." << endl; // 1
    cout << q.dequeue() << " dequeued from queue." << endl; // 2

    q.enqueue(5);

    cout << q.dequeue() << " dequeued from queue." << endl; // 3
    cout << q.dequeue() << " dequeued from queue." << endl; // 4
    cout << q.dequeue() << " dequeued from queue." << endl; // 5

    return 0;
}
