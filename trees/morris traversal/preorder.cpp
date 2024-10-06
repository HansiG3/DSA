#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node* create(node* root){
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout << "enter data for left of " << data << ": ";
    root->left = create(root->left);
    cout << "enter data for right of " << data << ": ";
    root->right = create(root->right);
    return root;
}

void preorder(node* root){
    node* current = root;
    while(current != NULL){
        if(current->left == NULL){
            // No left child, visit the node and move to the right
            cout << current->data << " ";
            current = current->right;
        }
        else {
            // Find the predecessor (rightmost node in the left subtree)
            node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                // Establish link and visit the node
                predecessor->right = current;
                cout << current->data << " ";  // Visit the current node
                current = current->left;
            }
            else {
                // Break the link (restore the tree structure)
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

int main(){
    node* root = NULL;
    root = create(root);
    cout << "Preorder Traversal: ";
    preorder(root);
    return 0;
}
