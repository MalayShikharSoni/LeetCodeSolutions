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
        
        ListNode* ahead = head;
        ListNode* behind = head;

        while(n) {
            ahead = ahead->next;
            n--;
        }

        if (!ahead) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* temp = behind->next;
        behind->next = behind->next->next;
        temp->next = nullptr;
        delete temp;
        
        return head;

    }
};