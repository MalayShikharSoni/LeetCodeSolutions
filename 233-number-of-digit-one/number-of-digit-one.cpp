class Solution {
public:

    int rec(int index, string& str, bool limit, int count, vector<vector<vector<int>>>& dp) {

        if(index == str.size()) {
            return count;
        }

        if(dp[index][limit][count] != -1) {
            return dp[index][limit][count];
        }

        int maxDigit = limit ? str[index] - '0' : 9;
        int ans = 0;

        for(int digit = 0; digit <= maxDigit; digit++) {

            if(digit == 1) {
                ans += rec(index + 1, str, limit && (digit == maxDigit), count + 1, dp);
            } else {
                ans += rec(index + 1, str, limit && (digit == maxDigit), count, dp);
            }

        }

        dp[index][limit][count] = ans;

        return ans;

    }

    int countDigitOne(int n) {
        
        string str = to_string(n);
        vector<vector<vector<int>>> dp(10, vector<vector<int>>(2, vector<int>(10, -1)));
        return rec(0, str, true, 0, dp);

    }
};