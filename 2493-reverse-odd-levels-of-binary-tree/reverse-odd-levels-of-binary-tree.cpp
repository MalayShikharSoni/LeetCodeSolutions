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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool reversed=false;

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> v(size);
            for(int i=0;i<size;i++){
                auto Node = q.front();
                q.pop();

                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);

                if(reversed){
                    v[i]=Node;

                    if(i>=size/2){
                        swap(v[i]->val, v[size-i-1]->val);
                    }
                }

            }
            reversed=!reversed;
        }

        return root;
    }
};