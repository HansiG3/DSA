#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        // Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // Merge the sorted halves
        return merge(left, right);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) 
            {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if (l1) curr->next = l1;
        if (l2) curr->next = l2;
        
        return dummy.next;
    }
};

ListNode* createLinkedList(int arr[], int n) 
{
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int i = 0; i < n; i++) 
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createLinkedList(arr, n);
    
    std::cout << "Original list: ";
    printList(head);
    
    Solution solution;
    ListNode* sortedHead = solution.sortList(head);
    
    std::cout << "Sorted list: ";
    printList(sortedHead);
    
    return 0;
}