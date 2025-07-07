class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int col = 0;
        int row = 0;
        int horizontal = 1;
        int vertical = 0;
        vector<int> ans;

        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[row][col]);
            matrix[row][col] = INT_MIN;

            if (!(0 <= col + horizontal && col + horizontal < n &&
                  0 <= row + vertical && row + vertical < m &&
                  matrix[row + vertical][col + horizontal] != INT_MIN)) {

                int temp = horizontal;
                horizontal = -vertical;
                vertical = temp;
            }

            col += horizontal;
            row += vertical;
        }

        return ans;
    }
};