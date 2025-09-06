class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {

        long long ans = 0;

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];
            long long rOps = getOps(right);
            long long lOps = left > 1 ? getOps(left - 1) : 0;
            ans += (rOps - lOps + 1) / 2;
        }

        return ans;
    }

    long long getOps(int n) {

        long long res = 0;
        long long ops = 0;
        long long p4 = 1;

        while (p4 <= n) {

            long long start = p4;
            long long end = min(4 * p4 - 1, (long long)n);
            ops++;

            res += (end - start + 1) * ops;
            p4 = 4 * p4;
        }

        return res;
    }
};