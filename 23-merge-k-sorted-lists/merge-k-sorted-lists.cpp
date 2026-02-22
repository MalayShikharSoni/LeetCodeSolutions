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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(ListNode* list : lists) {
            while(list) {
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;

        while(!pq.empty()) {
            merge->next = new ListNode(pq.top());
            pq.pop();
            merge = merge->next;
        }

        return dummy->next;

    }
};