class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        long long r1 = 0;
        long long r2 = 0;

        for(int i = 0; i < grid[0].size(); i++) {
            r1 += grid[0][i];
        }

        long long minPossibleScore = LLONG_MAX;

        for(int i = 0; i < grid[0].size(); i++) {

            r1 -= grid[0][i];

            long long maxScore = max(r1, r2);
            minPossibleScore = min(minPossibleScore, maxScore);

            r2 += grid[1][i];

        }

        return minPossibleScore;

    }
};