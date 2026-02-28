class Solution {
public:
    int findNextEvent(int low, int high, int currEnd, vector<vector<int>>& events) {
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (currEnd < events[mid][0]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;

    }

    int rec(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {

        if (i == events.size() || k == 0) {
            return 0;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        int skip = rec(i + 1, events, k, dp);
        int take = events[i][2];

        int currEnd = events[i][1];

        int j = findNextEvent(i + 1, events.size() - 1, currEnd, events);

        if (j != -1) {
            take += rec(j, events, k - 1, dp);
        }

        int ans = max(take, skip);

        dp[i][k] = ans;
        return ans;

    }
    
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return rec(0, events, k, dp);

    }
};