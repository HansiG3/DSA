#include<iostream>
#include<vector>
using namespace std;

class heap {
public:
    vector<int> v;
    
    heap() {
        v.push_back(-1);  // Use -1 to maintain 1-based indexing
    }

    void insert(int val) {
        // Insertion time complexity is O(logn)
        v.push_back(val);
        int index = v.size() - 1;
        while (index > 1) {
            int parent = index / 2;
            if (v[index] > v[parent]) {
                swap(v[parent], v[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void deletefromheap() {
        // TC of deletion is O(logn)
        if (v.size() <= 1) {
            cout << "Nothing to delete\n";
            return;
        }
        // Replace root with the last element
        v[1] = v[v.size() - 1];
        v.pop_back();

        int i = 1;
        while (i < v.size()) {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            int largest = i;

            if (leftindex < v.size() && v[largest] < v[leftindex]) {
                largest = leftindex;
            }
            if (rightindex < v.size() && v[largest] < v[rightindex]) {
                largest = rightindex;
            }

            if (largest != i) {
                swap(v[largest], v[i]);
                i = largest;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

// TC O(logn)
void heapify(vector<int>& v, int i,int size) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <size && v[largest] < v[left]) {
        largest = left;
    }
    if (right <size && v[largest] < v[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(v[largest], v[i]);
        heapify(v, largest,size);
    }
}
void heapsort(vector<int>&v,int size){
    while(size!=1){
        swap(v[1],v[size-1]);
        size--;
        heapify(v,1,size);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.deletefromheap();
    h.print();
    cout<<endl;
    // Manually building a heap from an unordered array
    vector<int> v = {-1, 54, 53, 55, 52, 50};  // The -1 ensures 1-based indexing
    int size=v.size();
    // Heapify the array (starting from the non-leaf nodes)
    for (int i = (v.size() / 2)-1; i > 0; i--) {
        heapify(v, i,size);
    }

    // Print the heap
    cout << "Heapified array:\n";
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    heapsort(v,size);
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
