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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(1);
        ListNode* merge = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                merge->next = list1;
                list1 = list1->next;
            } else {
                merge->next = list2;
                list2 = list2->next;
            }
            merge = merge->next;
        }

        if (merge->next == list1 && list1 == nullptr) {
            merge->next = list2;
        } else {
            merge->next = list1;
        }

        return dummy->next;
    }
};