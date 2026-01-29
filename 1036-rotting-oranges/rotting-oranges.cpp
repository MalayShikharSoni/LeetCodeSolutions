class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = -1;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<vector<int>> rottenQueue;
        int fresh = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                } else if(grid[r][c] == 2) {
                    rottenQueue.push({r, c});
                }
            }
        }

        if(fresh == 0) {
            return 0;
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!rottenQueue.empty()) {
            int size = rottenQueue.size();

            for(int i = 0; i < size; i++) {

                vector<int> front = rottenQueue.front();
                rottenQueue.pop();

                for(auto& dir : directions) {
                    int x = front[0] + dir[0];
                    int y = front[1] + dir[1];

                    if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                        fresh--;
                        grid[x][y] = 2;
                        rottenQueue.push({x, y});
                    }
                }

            }
            time++;

        }

        if(fresh) {
            return -1;
        }

        return time;

    }
};