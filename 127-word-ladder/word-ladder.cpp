class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int len = beginWord.size();
        unordered_map<string, vector<string>> allComboDict;

        for(string word : wordList) {

            for(int i = 0; i < len; i++) {
                string genericWord = word.substr(0, i) + '*' + word.substr(i + 1);
                allComboDict[genericWord].push_back(word);
            }

        }

        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;

        q.push({beginWord, 1});
        visited[beginWord] = true;

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            string currWord = curr.first;
            int currLevel = curr.second;

            for(int i = 0; i < len; i++) {

                string genericWord = currWord.substr(0, i) + '*' + currWord.substr(i + 1);

                for(string adjWord : allComboDict[genericWord]) {

                    if(adjWord == endWord) {
                        return currLevel + 1;
                    }

                    if(!visited[adjWord]) {
                        visited[adjWord] = true;
                        q.push({adjWord, currLevel + 1});
                    }

                }



            }

        }

        return 0;

    }
};