#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

node* floyd(node *head) { // Floyd's Cycle-Finding Algorithm
    if (head == NULL) return NULL;
    node *slow = head;
    node *fast = head;
    while (fast != NULL && slow != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow; // Loop detected
        }
    }
    return NULL; // No loop
}

// Function to find the starting node of the loop
node* loopstart(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *intersection = floyd(head);
    if (intersection == NULL) {
        return NULL; // No loop found
    }
    node *slow = head;
    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow; // Starting point of the loop
}
void removeloop(node *head){
    node *startpoint=loopstart(head);
    node*temp=startpoint;
    while(temp->next!=startpoint){
        temp=temp->next;
    }
    temp->next=NULL;
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    // Create a linked list with a loop for testing
    node *node1 = new node(10);
    node *node2 = new node(20);
    node *node3 = new node(30);
    node *node4 = new node(40);
    node *node5 = new node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2; // Creating a loop for testing

    node *head = node1;
    
    // Detect loop using Floyd's algorithm
    node *result = floyd(head);
    if (result != NULL) {
        cout << "Loop detected." << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    
    // Find the start of the loop
    node *startloop = loopstart(head);
    if (startloop != NULL) {
        cout << "Loop starts at element " << startloop->data << endl;
    } else {
        cout << "No loop start detected (shouldn't reach here if a loop was found)." << endl;
    }
    removeloop(head);
    print(head);

    return 0;
}
