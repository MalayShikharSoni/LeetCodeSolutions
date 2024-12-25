/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;

        q.push(root);
        int level=0;

        while(!q.empty()){
            int size=q.size();
            ans.push_back(INT_MIN);

            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                ans[level]=max(ans[level],node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            level++;
        }
        return ans;

        
    }
};