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
    ListNode* middleNode(ListNode* head) {
        
        int size = 0;

        ListNode* temp = head;

        while(temp) {
            size++;
            temp = temp -> next;
        }

        // int middle = (size % 2 == 0) ? size / 2 + 1 : size / 2;
        int middle = size / 2;

        int i = 1;
        temp = head;
        while(i <= middle) {
            temp = temp -> next;
            i++;
        }

        return temp;

    }
};