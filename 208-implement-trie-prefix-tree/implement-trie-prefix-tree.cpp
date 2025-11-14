class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char c) {
        return links[c - 'a'] != nullptr;
    }

    TrieNode* get(char c) {
        return links[c - 'a'];
    }

    void put(TrieNode* node, char c) {
        links[c - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndNode() {
        return isEnd;
    } 

};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* node = root;
        for(char c : word) {
            if(!node->containsKey(c)) {
                node->put(new TrieNode(), c);
            }
            node = node->get(c);
        }

        node->setEnd();

    }

    TrieNode* searchPrefix(string word) {

        TrieNode* node = root;

        for(char c : word) {
            if(node->containsKey(c)) {
                node = node->get(c);
            } else {
                return nullptr;
            }
        }

        return node;

    }
    
    bool search(string word) {
        
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndNode();
         
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = searchPrefix(prefix);
        if(node != nullptr) {
            return true;
        }

        return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */