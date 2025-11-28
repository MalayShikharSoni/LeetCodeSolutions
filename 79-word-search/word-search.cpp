class Solution {
public:
    vector<vector<char>> *board;
    int rows, cols;

    bool exist(vector<vector<char>>& board, string word) {
        this->board = &board;
        rows = board.size();
        cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(backTrack(r, c, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backTrack(int row, int col, string &word, int index) {
        if(index == word.size()) return true;

        if(row < 0 || row >= rows || col < 0 || col >= cols ||
           (*board)[row][col] != word[index]) {
            return false;
        }

        char temp = (*board)[row][col];
        (*board)[row][col] = '#';

        static int dr[4] = {0, 1, 0, -1};
        static int dc[4] = {1, 0, -1, 0};

        for(int d = 0; d < 4; d++) {
            if(backTrack(row + dr[d], col + dc[d], word, index + 1)) {
                (*board)[row][col] = temp;
                return true;
            }
        }

        (*board)[row][col] = temp;
        return false;
    }
};
