class TrieNode {
    public:
    bool isEnd;
    int count;
    TrieNode* child[26];

    TrieNode() {
        
        isEnd = false;
        count = 0;

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

        }

        curr->isEnd = true;

    }

    int search(string& word) {

        TrieNode* curr = root;
        int ans = 0;

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];
            int index = ch - 'a';

            if(curr->child[index] == nullptr) {
                return ans;
            }

            curr = curr->child[index];
            ans += curr->count;

        }

        return ans;

    }

};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie trie;

        for(string word : words) {
            trie.insert(word);
        }

        vector<int> ans(words.size());

        for(int i = 0; i < words.size(); i++) {
            int count = trie.search(words[i]);
            ans[i] = count;
        }

        return ans;

    }
};