/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void recSerialize(TreeNode* node, string& str) {

        if (node == nullptr) {
            str += "null,";
            return;
        } else {
            str += to_string(node->val) + ",";
            recSerialize(node->left, str);
            recSerialize(node->right, str);
        }
    }

    string serialize(TreeNode* root) {

        string str = "";
        recSerialize(root, str);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* recDeserialize(list<string>& strs) {

        if (strs.front() == "null") {
            strs.pop_front();
            return nullptr;
        }

        int value = stoi(strs.front());
        strs.pop_front();

        TreeNode* root = new TreeNode(value);
        root->left = recDeserialize(strs);
        root->right = recDeserialize(strs);

        return root;
    }

    TreeNode* deserialize(string data) {

        list<string> strs;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                strs.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return recDeserialize(strs);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));