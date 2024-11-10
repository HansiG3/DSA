#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& v, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && v[largest] < v[left]) {
        largest = left;
    }
    if (right < size && v[largest] < v[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(v[largest], v[i]);
        heapify(v, largest, size);
    }
}

int main() {
    vector<int> v1;
    vector<int> v2;
    int element1 = 0;
    int element2 = 0;

    cout << "Enter elements for vector 1 (enter -1 to stop): ";
    while (true) {
        cin >> element1;
        if (element1 == -1) break;
        v1.push_back(element1);
    }

    cout << "Enter elements for vector 2 (enter -1 to stop): ";
    while (true) {
        cin >> element2;
        if (element2 == -1) break;
        v2.push_back(element2);
    }

    vector<int> v3;
    for (int i = 0; i < v1.size(); i++) {
        v3.push_back(v1[i]);
    }
    for (int i = 0; i < v2.size(); i++) {
        v3.push_back(v2[i]);
    }

    for (int i = (v3.size() / 2) - 1; i >= 0; i--) {
        heapify(v3, i, v3.size());
    }

    cout << "Max Heap: ";
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }

    return 0;
}
