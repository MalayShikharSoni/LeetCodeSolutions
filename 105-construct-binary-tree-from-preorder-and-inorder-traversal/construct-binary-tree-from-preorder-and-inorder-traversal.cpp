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
    int index = 0;
    unordered_map<int, int> inorderMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int start, int end) {

        if(start > end) {
            return nullptr;
        }

        int rootVal = preorder[index];
        index++;

        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->left = helper(preorder, start, mid - 1);
        root->right = helper(preorder, mid + 1, end);

        return root;

    }

};