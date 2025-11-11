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
    int prev;
    bool hasPrev;

    bool isValidBST(TreeNode* root) {
        prev = INT_MIN;
        hasPrev = false;
        return inOrder(root);
    }

    bool inOrder(TreeNode* node) {

        if(node == nullptr) {
            return true;
        }

        if(!inOrder(node->left)) {
            return false;
        }

        if(hasPrev && node->val <= prev) {
            return false;
        }

        prev = node->val;
        hasPrev = true;

        return inOrder(node->right);

    }
};