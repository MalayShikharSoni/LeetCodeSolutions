class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if(wordSet.find(beginWord) != wordSet.end()) {
            wordSet.erase(beginWord);
        }

        while(!q.empty()) {

            string top = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(top == endWord) {
                return steps;
            }

            for(int i = 0; i < top.size(); i++) {

                char original = top[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    top[i] = ch;
                    if(wordSet.find(top) != wordSet.end()) {
                        q.push({top, steps + 1});
                        wordSet.erase(top);
                    }

                }

                top[i] = original;

            }

        }

        return 0;

    }
};