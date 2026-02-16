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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) {
            return 0;
        }

        long long width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int levelSize = q.size();
            long long first = q.front().second;
            long long last = first;

            for(int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front().first;
                long long ind = q.front().second;
                q.pop();

                ind = ind - first;
                last = ind;

                if(node->left) {
                    q.push({node->left, ind * 2});
                }

                if(node->right) {
                    q.push({node->right, ind* 2 + 1});
                }

            }

            width = max(width, last + 1);

        }

        return (int)width;

    }
};