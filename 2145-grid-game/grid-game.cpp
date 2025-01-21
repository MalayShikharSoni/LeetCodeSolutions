class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long r1 = 0;
        long long r2 = 0;

        for(int i=0;i<grid[0].size();i++){
            r1 += grid[0][i];
        }

        long long minAns = LLONG_MAX;

        for(int i=0;i<grid[0].size();i++){
            r1 -= grid[0][i];

            long long maxScore = max(r1,r2);

            minAns = min(minAns, maxScore);

            r2 += grid[1][i];
        }

        return minAns;
    }
};