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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        
        ListNode *head = nullptr;
        ListNode *currPtr = nullptr;
        ListNode *first = l1;
        ListNode *second = l2;
        
        while (l1 != nullptr && l2 != nullptr) {
            int firstVal = l1->val;
            int secondVal = l2->val;

            if (firstVal <= secondVal) {
                // curr -> first
                if (currPtr == nullptr) {
                    currPtr = l1;
                    head = l1;
                } else {
                    currPtr->next = l1;
                    currPtr = currPtr->next;
                }
                l1 = l1->next;
            } else {
                // curr -> second
                if (currPtr == nullptr) {
                    currPtr = l2;
                    head = l2;
                } else {
                    currPtr->next = l2;
                    currPtr = currPtr->next;
                }
                l2 = l2->next;
            }
        }
        
        if (l1 == nullptr) {
            currPtr->next = l2;
        } else {
            currPtr->next = l1;
        }
        
        return head;
    }
};
