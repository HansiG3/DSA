#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int firstNonRepeatingCharacter(string s) {
    unordered_map<char, int> freq; // To store the frequency of each character
    queue<int> q; // To store the indices of characters as they appear
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        freq[c]++; // Increment the frequency of the character
        q.push(i); // Push the index of the character into the queue
        
        // Remove characters from the front of the queue while they are repeating
        while (!q.empty() && freq[s[q.front()]] > 1) {
            q.pop();
        }
    }
    
    // Check the front of the queue
    if (!q.empty()) {
        return q.front(); // Index of the first non-repeating character
    }
    
    return -1; // No non-repeating character found
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    int index = firstNonRepeatingCharacter(s);
    if (index != -1) {
        cout << "The first non-repeating character is at index: " << index << endl;
    } else {
        cout << "No non-repeating character found" << endl;
    }

    return 0;
}
