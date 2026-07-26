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
    vector<TreeNode*> generateTrees(int n) {
        
        if(n == 0) {
            return {};
        }

        return solve(1, n);

    }

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> trees;

        if(start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for(int root = start; root <= end; root++) {

            vector<TreeNode*> leftTrees = solve(start, root - 1);
            vector<TreeNode*> rightTrees = solve(root + 1, end);

            for(auto left : leftTrees) {

                for(auto right : rightTrees) {

                    TreeNode* curr = new TreeNode(root);

                    curr->left = left;
                    curr->right = right;

                    trees.push_back(curr);

                }

            }

        } 

        return trees;

    }

};