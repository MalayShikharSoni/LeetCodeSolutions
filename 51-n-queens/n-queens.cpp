class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));
        backTrack(0, board, ans);

        return ans;

    }

    void backTrack(int col, vector<string>& board, vector<vector<string>>& ans) {

        if(col == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++) {

            if(isValid(board, row, col)) {

                board[row][col] = 'Q';
                backTrack(col + 1, board, ans);
                board[row][col] = '.';
            }

        }

    }

    bool isValid(vector<string>& board, int row, int col) {

        for(int c = 0; c < col; c++) {
            if(board[row][c] == 'Q') {
                return false;
            }
        }

        for(int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }

        for(int r = row, c = col; r < board.size() &&  c >= 0; r++, c--) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }

        return true;
    }

};