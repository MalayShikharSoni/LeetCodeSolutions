class Solution {
public:
    int totalNQueens(int n) {
        
        int count = 0;
        vector<string> board(n, string(n, '.'));

        backtrack(0, board, count);

        return count;
    }

    void backtrack(int col, vector<string>& board, int& count) {

        if(col == board.size()) {
            count++;
            return;
        }

        for(int row = 0; row < board.size(); row++) {

            if(isValid(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(col + 1, board, count);
                board[row][col] = '.';
            }

        }

    }

    bool isValid(int row, int col, vector<string>& board) {

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

        for(int r = row, c = col; r < board.size() && c >= 0; r++, c--) {
            if(board[r][c] == 'Q') {
                return false;
            }
        }

        return true;

    }
};