class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {

            if(grid[i][0] == 0) {

                for(int j = 0; j < n; j++) {

                    grid[i][j] ^= 1;

                }

            }

        }

        int ans = 0;

        for(int j = 0; j < n; j++) {

            int ones = 0;

            for(int i = 0; i < m; i++) {
                ones += grid[i][j];
            }

            int maxx = max(ones, m - ones);

            ans += maxx * (1 << (n - j - 1));

        } 

        return ans;

    }
};