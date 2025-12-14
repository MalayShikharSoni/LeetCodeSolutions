class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if((r == 0 || c == 0 || r == rows - 1 || c == cols - 1) && board[r][c] == 'O') {
                    dfs(board, r, c);
                } 

            }
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'T') {
                    board[r][c] = 'O';
                } else if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, int r, int c) {

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';

        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);

    }

};