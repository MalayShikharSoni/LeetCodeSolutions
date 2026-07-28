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
        
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        int nodes = 0;
        ListNode* curr = head;

        while(curr) {
            nodes++;
            curr = curr->next;
        }

        if(nodes <= 1) {
            return nullptr;
        }

        int toDelete = nodes - n + 1;

        if(toDelete == 1) {
            return head->next;
        }

        ListNode* prev = dummy;
        curr = head;

        for(int i = 1; i < toDelete; i++) {
            
            prev = prev->next;
            curr = curr->next;

        }

        prev->next = curr->next;
        delete curr;
        
        return dummy->next;

    }
};