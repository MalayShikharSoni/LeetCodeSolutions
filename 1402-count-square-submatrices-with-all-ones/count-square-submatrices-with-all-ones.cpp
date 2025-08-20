class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();

        if(m == 0) {
            return 0;
        }

        int n = matrix[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]}) + 1;
                }

                ans += matrix[i][j];

            }

            
        }

            return ans;
    }
};