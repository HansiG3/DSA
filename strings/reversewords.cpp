#include<iostream>
#include<string>
using namespace std;

// Corrected swap function
void swap(char &a, char &b){
    char t = a;
    a = b;
    b = t;
}

int main(){
    string str;
    string temp;
    cout << "enter the string: ";
    getline(cin, str);
    int len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i] != ' '){
            temp.push_back(str[i]);
        } else {
            // Reverse the word in temp
            int start = 0;
            int end = temp.length() - 1;
            while(start < end){
                swap(temp[start], temp[end]);
                start++;
                end--;
            }
            // Output the reversed word
            cout << temp << ' ';
            temp = "";  // Clear temp for the next word
        }
    }

    // Handle the last word
    if (!temp.empty()) {
        int start = 0;
        int end = temp.length() - 1;
        while(start < end){
            swap(temp[start], temp[end]);
            start++;
            end--;
        }
        cout << temp;  // Print the last reversed word
    }

    return 0;
}
