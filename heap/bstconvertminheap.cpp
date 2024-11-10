#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* create(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }
    if (d > root->data) {
        root->right = create(root->right, d);
    } else {
        root->left = create(root->left, d);
    }
    return root;
}

void inorder(node* root, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void buildMinHeap(vector<int>& v, node* root, int& index) {
    if (root == NULL) {
        return;
    }
    root->data = v[index++];
    buildMinHeap(v, root->left, index);
    buildMinHeap(v, root->right, index);
}

int main() {
    node* root = NULL;
    int d;
    cout << "Enter elements for the tree (enter -1 to stop): ";
    cin >> d;
    while (d != -1) {
        root = create(root, d);
        cin >> d;
    }

    vector<int> v;
    inorder(root, v); // Get the sorted elements from BST

    int index = 0;
    buildMinHeap(v, root, index); // Build min-heap from sorted elements

    cout << "Min-Heap: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
