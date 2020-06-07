/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode *currPtr = head;
        while (currPtr != nullptr) {
            size++;
            currPtr = currPtr->next;
        }
        
        
        currPtr = head;
        // find second sect
        for (int i = 0; i < size / 2; i++) {
            currPtr = currPtr->next;
        }
        
        
        if (size % 2 == 1) {
            // skip 1 node if odd size
            currPtr = currPtr->next;
        }
        
        ListNode *secondHead = reverse(currPtr);
        currPtr = head;
        for (int i = 0; i < size / 2; i++) {
            int firstVal = currPtr->val;
            int secondVal = secondHead->val;
            if (firstVal != secondVal) {
                return false;
            }
            currPtr = currPtr->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *reversedTail = reverse(head->next);
        ListNode *tail = head->next->next;
        ListNode *beforeTail = head->next;
        head->next = tail;
        beforeTail->next = head;
        //head->next->next = head;
        return reversedTail;
    }
};
