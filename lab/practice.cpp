#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* getnode(node*head,int mid){
    node* temp=head;
    int count=0;
    while(count<mid){
        temp=temp->next;
        count++;
    }
    return temp;
}
int binarysearch(node*&head,int key){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int start=0;
    int end=count-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        node* middle=getnode(head,mid);
        if(middle->data==key){
            cout<<"found "<<mid;
            return 1;
        }
        else if(middle->data>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return 0;
}
node* insertEnd(node* head, int value){
    node* temp = new node(value);
    if(head == NULL){
        head = temp;
    } else {
        node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return head;
}

// Function to print the linked list
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node* head = NULL;

    // Insert elements into the list (make sure they are sorted)
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    head = insertEnd(head, 60);

    printList(head);

    int target = 30;
    binarysearch(head, target);

    return 0;
}
