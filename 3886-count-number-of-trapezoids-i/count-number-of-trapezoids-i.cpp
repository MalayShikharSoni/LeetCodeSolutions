class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        long long ans = 0;
        long long sum = 0;
        int mod = 1000000007;

        unordered_map<int, int> yFreq;

        for(auto& point : points) {
            yFreq[point[1]]++;
        }

        for(auto [y, numX] : yFreq) {

            long long combinations = (long long)numX * (numX - 1) / 2;
            ans = (ans + (sum * combinations) % mod) % mod;
            sum = (sum + combinations) % mod;

        }

        return ans;

    }
};