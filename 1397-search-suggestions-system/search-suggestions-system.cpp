class TrieNode {
    public:
    bool isEnd;
    int count;
    vector<string> searches;
    TrieNode* child[26];

    TrieNode() {
        
        isEnd = false;
        count = 0;
        searches = {};

        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }

    }

};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {

        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];
            int index = ch - 'a';

            if(curr->child[index] == nullptr) {
                TrieNode* temp = new TrieNode();
                curr->child[index] = temp;
            }

            curr = curr->child[index];
            curr->count++; 
            curr->searches.push_back(word);

        }
        curr->isEnd = true;

    }

    vector<vector<string>> search(string& word) {

        TrieNode* curr = root;
        vector<vector<string>> ans;

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];
            int index = ch - 'a';

            if(curr->child[index] == nullptr) {
                while(ans.size() < word.size()) {
                    ans.push_back({});
                }
                return ans;
            }

            curr = curr->child[index];
            vector<string> vec;
            int minn = 3;
            int size = curr->searches.size();
            if(size < minn) {
                minn = size;
            }

            for(int i = 0; i < minn; i++) {
                vec.push_back(curr->searches[i]);
            }

            ans.push_back(vec);

        }

        return ans;

    }

};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie trie;
        sort(products.begin(), products.end());
        for(string product : products) {
            trie.insert(product);
        }

        return trie.search(searchWord);

    }
};