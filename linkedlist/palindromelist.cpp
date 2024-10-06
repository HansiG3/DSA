#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void ispalindrome(node *&head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int *arr=new int[count];
    temp=head;
    int i=0;
    while(temp!=NULL){
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }
    int start=0;
    int end=count-1;
    int flag=1;
    while(start<end){
        if(arr[start]!=arr[end]){
            flag=0;
            break;
        }
        start++;
        end--;
    }
    if(flag==1){
        cout<<"is a palindrome "<<endl;
    }
    else{
        cout<<"not a palindrome "<<endl;
    }
}
int main(){
    node *head1=new node(10);
    head1->next=new node(20);
    head1->next->next=new node(20);
    head1->next->next->next=new node(10);
    ispalindrome(head1);
}