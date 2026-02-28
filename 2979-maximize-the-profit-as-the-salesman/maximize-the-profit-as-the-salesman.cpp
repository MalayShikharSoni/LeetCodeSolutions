class Solution {
public:

    int findNextOffer(int low, int high, int currEnd, vector<vector<int>>& offers) {

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(offers[mid][0] > currEnd) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return ans;

    }

    int rec(int i, vector<vector<int>>& offers, vector<int>& dp) {

        if(i == offers.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int skip = rec(i + 1, offers, dp);
        int take = offers[i][2];
        int currEnd = offers[i][1];

        int j = findNextOffer(i + 1, offers.size() - 1, currEnd, offers);

        if(j != -1) {
            take += rec(j, offers, dp);
        }

        int ans = max(take, skip);
        dp[i] = ans;

        return ans;

    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        vector<int> dp(offers.size(), -1);
        sort(offers.begin(), offers.end());
        return rec(0, offers, dp);

    }
};