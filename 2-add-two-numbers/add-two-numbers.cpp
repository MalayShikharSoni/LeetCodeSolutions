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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;

        while(l1 && l2) {
            
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* curr = new ListNode(sum);
            head->next = curr;
            head = head->next; 
            l1 = l1->next;
            l2 = l2->next;

        }

        if(l1) {
            head->next = l1;
        } else if(l2) {
            head->next = l2;
        }

        while(l1) {
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1 = l1->next;
            head = head->next;
        }

        while(l2) {
            l2->val += carry;
            carry = l2->val / 10;
            l2->val %= 10;
            l2 = l2->next;
            head = head->next;
        }

        if(carry) {
            head->next = new ListNode(carry);
        }

        return dummy->next;

        

    }
};