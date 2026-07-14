class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(n == 1) {
            return grid[0][0];
        }

        vector<int> prev;
        prev = grid[0];

        for(int i = 1; i < n; i++) {

            int min1 = INT_MAX;
            int min2 = INT_MAX;
            int minIndex = -1;

            for(int j = 0; j < n; j++) {

                if(prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    minIndex = j;
                } else if(prev[j] < min2) {
                    min2 = prev[j];
                }

            }

            vector<int> curr(n);
            
            for(int j = 0; j < n; j++) {

                if(j == minIndex) {
                    curr[j] = grid[i][j] + min2;
                } else {
                    curr[j] = grid[i][j] + min1;
                }

            }

            prev = curr;

        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, prev[i]);
        }

        return ans;

    }
};