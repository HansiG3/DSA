#include<iostream>
#include<map>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    
    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to create a binary tree
node* create(node* root) {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;  // Treat -1 as NULL (no child)
    }
    
    root = new node(data);
    cout << "Enter data for left of " << data << ": ";
    root->left = create(root->left);
    cout << "Enter data for right of " << data << ": ";
    root->right = create(root->right);
    return root;
}

// Function to map each node to its parent and locate the target node
node* nodetoparent(node* root, map<node*, node*>& nodeparent, node*& targetroot, int value) {
    queue<node*> q;
    q.push(root);
    nodeparent[root] = NULL;  // Root has no parent
    
    while(!q.empty()) {
        node* front = q.front();
        q.pop();
        
        if(front->data == value) {
            targetroot = front;  // Found the target node
        }
        
        if(front->left) {
            nodeparent[front->left] = front;
            q.push(front->left);
        }
        
        if(front->right) {
            nodeparent[front->right] = front;
            q.push(front->right);
        }
    }
    return targetroot;
}

// Function to simulate burning the tree and return time taken
int burntree(node* targetroot, map<node*, node*>& nodeparent, int& time) {
    if(!targetroot) {
        return -1;  // If target node is not found, return -1 or handle appropriately
    }

    map<node*, bool> visited;
    queue<node*> q;
    
    q.push(targetroot);
    visited[targetroot] = true;
    
    while(!q.empty()) {
        int size = q.size();
        bool flag = false;  // Check if new nodes will burn in this cycle
        
        for(int i = 0; i < size; i++) {
            node* front = q.front();
            q.pop();
            
            // Process the left child
            if(front->left && !visited[front->left]) {
                q.push(front->left);
                visited[front->left] = true;
                flag = true;
            }
            
            // Process the right child
            if(front->right && !visited[front->right]) {
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }
            
            // Process the parent node
            if(nodeparent[front] && !visited[nodeparent[front]]) {
                q.push(nodeparent[front]);
                visited[nodeparent[front]] = true;
                flag = true;
            }
        }
        
        if(flag) {
            time++;  // Increment time if we burned any new nodes
        }
    }
    return time;
}

int main() {
    node* root = NULL;
    cout << "Enter data for the tree (use -1 for NULL node): " << endl;
    root = create(root);  // Create the binary tree
    
    int value;
    cout << "Enter the target node value to start the fire: ";
    cin >> value;
    
    map<node*, node*> nodeparent;  // Map to store parent pointers for each node
    node* targetroot = NULL;  // Initialize targetroot
    
    // Find the target node and populate the parent map
    targetroot = nodetoparent(root, nodeparent, targetroot, value);
    
    if(targetroot == NULL) {
        cout << "Target node not found!" << endl;
        return 0;
    }
    
    int time = 0;
    time = burntree(targetroot, nodeparent, time);  // Calculate the time to burn the tree
    
    // Output the result
    cout << "Time to burn the tree: " << time << " units." << endl;
    
    return 0;
}
