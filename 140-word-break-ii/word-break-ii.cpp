class Solution {
public:

    void backtrack(int index, string curr, vector<string>& ans, string s, unordered_set<string>& wordSet) {

        if(index == s.size()) {

            curr.pop_back();
            ans.push_back(curr);
            return;

        }

        for(int i = index; i < s.size(); i++) {

            string word = s.substr(index, i - index + 1);

            if(wordSet.count(word)) {

                backtrack(i + 1, curr + word + " ", ans, s, wordSet);

            }

        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> ans;

        backtrack(0, "", ans, s, wordSet);

        return ans;

    }
};