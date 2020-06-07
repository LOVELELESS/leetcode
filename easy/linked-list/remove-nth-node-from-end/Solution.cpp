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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> v;
        ListNode *currptr = head;
        for (int i = 0; i < n + 1; i++) {
            if (currptr == nullptr) {
                // means delete 1st node -> return 2nd node
                if (v.size() > 1) {
                    return v[1];
                } else {
                    return nullptr;
                }
            }
            v.push_back(currptr);
            currptr = currptr->next;
        }
        
        while (currptr != NULL) {
            // have not reached end
            v.erase(v.begin());
            v.push_back(currptr);
            currptr = currptr->next;
        }

        // reached end, delete the first node in vector
        ListNode *prevNode = v[0];
        prevNode->next = prevNode->next->next;
        
        return head;
    }
};
