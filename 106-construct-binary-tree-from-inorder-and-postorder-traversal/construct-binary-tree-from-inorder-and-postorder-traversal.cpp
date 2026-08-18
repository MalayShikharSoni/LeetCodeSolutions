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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend) {

        if(instart > inend || poststart > postend) {
            return nullptr;
        }

        int rootval = postorder[postend];
        TreeNode* root = new TreeNode(rootval);

        int index = instart;

        while(inorder[index] != rootval) {
            index++;
        }

        int leftSize = index - instart;

        root->left = build(inorder, postorder, instart, index - 1, poststart, poststart + leftSize - 1);
        root->right = build(inorder, postorder, index + 1, inend, poststart + leftSize, postend - 1);

        return root;

    }

};