class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }

};

class WordDictionary {
public:
    TrieNode* root;
 
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode* node = root;

        for(char c : word) {

            if(node->children.find(c) == node->children.end()) {

                node->children[c] = new TrieNode();

            }

            node = node->children[c];

        }

        node->isEnd = true;

    }

    bool searchInNode(string word, TrieNode* node) {

        for(int i = 0; i < word.size(); i++) {

            char c = word[i];
            if(node->children.find(c) == node->children.end()) {

                if(c == '.') {
                    for(auto& n : node->children) {
                        TrieNode* child = n.second;

                        if(searchInNode(word.substr(i + 1), child)) {
                            return true;
                        }
                    }

                    return false;
                }

                return false;

            }

            node = node->children[c];

        }

        return node->isEnd
        ;

    }
    
    bool search(string word) {
        return searchInNode(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */