/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) { return countGoodNodes(root, INT_MIN); }

    int countGoodNodes(TreeNode* node, int maxSoFar) {

        if (node == nullptr) {
            return 0;
        }

        int count = 0;
        if (node->val >= maxSoFar) {
            count = 1;
            maxSoFar = node->val;
        }

        count += countGoodNodes(node->left, maxSoFar);
        count += countGoodNodes(node->right, maxSoFar);

        return count;
    }
};