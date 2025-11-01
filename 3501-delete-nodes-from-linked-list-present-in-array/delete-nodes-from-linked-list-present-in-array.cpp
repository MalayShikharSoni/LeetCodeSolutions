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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;

        for (int num : nums) {
            s.insert(num);
        }

        if (!head)
            return nullptr;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(1);
        dummy->next = curr;
        ListNode* prev = dummy;

        while (curr) {

            if (s.find(curr->val) != s.end()) {

                prev->next = curr->next;
                curr = prev->next;

            } else {

                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};