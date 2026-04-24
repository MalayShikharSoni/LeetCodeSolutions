class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp(3, 0);

        for(int i = n - 1; i >= 0; i--) {

            int one = stoneValue[i] - dp[(i + 1) % 3];
            
            int two = INT_MIN;
            if(i + 1 < n) {
                two = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];
            }

            int three = INT_MIN;
            if(i + 2 < n) {
                three = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3];
            }

            dp[i % 3] = max({one, two, three});

        }

        if(dp[0] > 0) {
            return "Alice";
        } else if(dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }

    }
};