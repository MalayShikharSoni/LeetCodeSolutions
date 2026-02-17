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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) {
            return {};
        }
        vector<vector<int>> ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                q.pop();
                level.push_back(node->val);

                if(node->left) {
                    q.push({node->left, node->left->val});
                    
                }
                if(node->right) {
                    q.push({node->right, node->right->val});
                    
                }
            }

            ans.push_back(level); 
        }

        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 != 0) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }

        return ans;

    }
};