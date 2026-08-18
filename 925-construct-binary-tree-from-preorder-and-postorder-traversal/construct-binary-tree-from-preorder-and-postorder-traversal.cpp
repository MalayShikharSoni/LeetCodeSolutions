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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        return build(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);

    }

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int prestart, int preend, int poststart, int postend) {

        if(prestart > preend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        if(prestart == preend) {
            return root;
        }

        int leftroot = preorder[prestart + 1];

        int index = poststart;
        while(postorder[index] != leftroot) {
            index++;
        }

        int leftsize = index - poststart + 1;

        root->left = build(preorder, postorder, prestart + 1, prestart + leftsize, poststart, index);
        root->right = build(preorder, postorder, prestart + leftsize + 1, preend, index + 1, postend - 1);

        return root;

    }

};  