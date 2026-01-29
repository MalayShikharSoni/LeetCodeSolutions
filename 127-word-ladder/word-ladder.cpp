class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> dictionary;

        for(string word: wordList) {

            for(int i = 0; i < word.size(); i++) {
                string genericWord = word.substr(0, i) + '*' + word.substr(i + 1);
                dictionary[genericWord].push_back(word);
            }

        }

        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;

        q.push({beginWord, 1});
        visited[beginWord] = true;

        while(!q.empty()) {

            string frontWord = q.front().first;
            int frontLevel = q.front().second;
            q.pop();

            for(int i = 0; i < frontWord.size(); i++) {
                string frontGeneric = frontWord.substr(0, i) + '*' + frontWord.substr(i + 1);
                
                for(string w : dictionary[frontGeneric]) {
                    if(w == endWord) {
                        return frontLevel + 1;
                    }
                    if(!visited[w]) {
                        visited[w] = true;
                        q.push({w, frontLevel + 1});
                    }
                }
            }

        }

        return 0;


    }
};