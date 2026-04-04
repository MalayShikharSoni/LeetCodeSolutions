class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            
            dp[i] = 1 + dp[i + 1];

            for(string word : dictionary) {

                if(s.compare(i, word.size(), word) == 0) {
                    dp[i] = min(dp[i], dp[i + word.size()]);
                }

            }

        }

        return dp[0];

    }
};