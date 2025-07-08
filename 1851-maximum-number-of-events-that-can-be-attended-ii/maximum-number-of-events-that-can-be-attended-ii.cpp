class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 return x[1] < y[1];
             });

        int n = events.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {

            int latest = binarySearch(events, events[i - 1][0]);

            for (int j = 1; j <= k; j++) {
                dp[i][j] =
                    max(dp[i - 1][j], dp[latest + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }

    int binarySearch(vector<vector<int>>& events, int start) {
        int left = 0;
        int right = events.size() - 1;
        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (events[mid][1] < start) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};