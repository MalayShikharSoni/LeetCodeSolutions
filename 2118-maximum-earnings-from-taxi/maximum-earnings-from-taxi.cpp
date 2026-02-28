class Solution {
public:
    int findNextRide(int low, int high, int currEnd,
                     vector<vector<int>>& rides) {

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (rides[mid][0] >= currEnd) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    long long rec(int i, vector<vector<int>>& rides, vector<long long>& dp) {

        if (i == rides.size()) {
            return 0;
        }

        if (dp[i] != -1L) {
            return dp[i];
        }

        long long skip = rec(i + 1, rides, dp);
        long long take = rides[i][1] - rides[i][0] + rides[i][2];
        int currEnd = rides[i][1];

        int j = findNextRide(i + 1, rides.size() - 1, currEnd, rides);

        if (j != -1) {
            take += rec(j, rides, dp);
        }

        long long ans = max(take, skip);
        dp[i] = ans;

        return ans;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        vector<long long> dp(rides.size(), -1);
        sort(rides.begin(), rides.end());
        return rec(0, rides, dp);
    }
};