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

    int gcd(int a, int b) {

        int gcd = 1;
        for(int i = 2; i <= min(a, b); i++) {
            if(a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }

        return gcd;

    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* one = head;
        ListNode* two = head->next;

        while(two) {

            int g = gcd(one->val, two->val);
            ListNode* neww = new ListNode(g);

            one->next = neww;
            neww->next = two;

            one = two;
            two = two->next;

        }

        return dummy->next;

    }
};