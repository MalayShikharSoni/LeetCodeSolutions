class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {

        long long ans = 0;
        vector<vector<int>> right(n + 1);

        for (auto& pair : conflictingPairs) {
            right[max(pair[0], pair[1])].push_back(min(pair[0], pair[1]));
        }

        long long firstMax = 0;
        long long secondMax = 0;
        vector<long long> bonus(n + 1, 0);

        for (int r = 1; r <= n; r++) {
            for (int left : right[r]) {

                if (left > firstMax) {
                    secondMax = firstMax;
                    firstMax = left;
                } else if (left > secondMax) {
                    secondMax = left;
                }
            }

            ans += r - firstMax;

            if (firstMax > 0) {
                bonus[firstMax] += firstMax - secondMax;
            }
        }

        long long max_bonus = 0;
        for (long long b : bonus) {
            max_bonus = max(max_bonus, b);
        }

        return ans + max_bonus;
    }
};