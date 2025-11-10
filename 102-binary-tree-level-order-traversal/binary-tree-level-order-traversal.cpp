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

    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root )
        order(root, 0);
        return ans;

    }

    void order(TreeNode* node, int level) {

        if(ans.size() == level) {
            ans.push_back({});
        }

        ans[level].push_back(node->val);

        if(node->left) {
            order(node->left, level + 1);
        }
        if(node->right) {
            order(node->right, level + 1);
        }

    }
};