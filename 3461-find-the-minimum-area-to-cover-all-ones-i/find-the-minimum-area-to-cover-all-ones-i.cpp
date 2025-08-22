class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int mini = INT_MAX;
        int minj = INT_MAX;
        int maxi = INT_MIN;
        int maxj = INT_MIN;


        for(int i = 0; i < grid.size(); i++) {

            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 1) {
                    mini = min(mini, i + 1);
                    minj = min(minj, j + 1);
                    maxi = max(maxi, i + 1);
                    maxj = max(maxj, j + 1);
                }

            }

        }

        return (maxi - mini + 1) * (maxj - minj + 1); 

    }
};