#include<iostream>
#include<vector>
using namespace std;

class q {
public:
    int size;
    int front;
    int rear;
    int *arr;

    q(int size) {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int value) {
        // Check if the queue is full
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
            return;  // Exit the function if the queue is full
        }

        // If the queue is empty, initialize front to 0
        if (front == -1) {
            front = 0;
        }

        // Insert the value into the queue
        rear++;
        arr[rear] = value;
        cout << value << " added to the queue" << endl;
    }

    void pop() {
        // Check if the queue is empty
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;  // Exit the function if the queue is empty
        }

        // Remove the front element from the queue
        cout << arr[front] << " removed from the queue" << endl;
        front++;

        // If the queue becomes empty after removing the last element, reset front and rear
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    bool isempty() {
        return (front == -1);
    }
    bool isfull(){
        return(rear==size-1);
    }
    void print(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i];
        }
    }
};
int main() {
    q q1(20);
    int num;
    cout<<"enter the value of num";
    cin>>num;
    vector<int>v;
    for(int i=1;i<=num;i++){
        int temp=i;
        while(temp/2!=0){
            if(!q1.isfull()){
                v.push_back(temp%2);
            }
            temp=temp/2;
        }
        v.push_back(temp%2);
        for(int i=v.size()-1;i>=0;i--){
            q1.push(v[i]);
        }
        v.clear();
    }
    q1.print();
}
