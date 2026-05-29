class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> rank;

        for(int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int j = 0;

            while(j < word1.size() && j < word2.size()) {

                char c1 = word1[j];
                char c2 = word2[j];

                if(c1 != c2) {

                    if(rank[c1] > rank[c2]) {
                        return false;
                    }

                    break;

                }

                j++;

            }

            if(j == word2.size() && word1.size() > word2.size()) {
                return false;
            }

        }

        return true;

    }
};