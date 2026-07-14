class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        if(n == 1) {
            return matrix[0][0];
        }

        vector<int> prev;
        prev = matrix[0];

        for(int i = 1; i < n; i++) {

            vector<int> curr(n);

            for(int j = 0; j < n; j++) {

                curr[j] = prev[j];
                
                if(j - 1 >= 0) {
                    curr[j] = min(curr[j], prev[j - 1]);
                }

                if(j + 1 < n) {
                    curr[j] = min(curr[j], prev[j + 1]);
                }

                curr[j] += matrix[i][j];

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