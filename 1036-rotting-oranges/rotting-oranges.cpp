class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if (grid.size() == 0) {
            return -1;
        }

        int freshOranges = 0;
        queue<vector<int>> rottenQueue;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }

        if (freshOranges == 0)
            return 0;

        int minutes = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!rottenQueue.empty()) {

            int size = rottenQueue.size();
            for (int i = 0; i < size; i++) {

                vector<int> rotten = rottenQueue.front();
                rottenQueue.pop();

                for (auto& dir : directions) {

                    int x = rotten[0] + dir[0];
                    int y = rotten[1] + dir[1];

                    if (x >= 0 && x < grid.size() && y >= 0 &&
                        y < grid[0].size() && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        freshOranges--;
                        rottenQueue.push({x, y});
                    }
                }
            }
            minutes++;
        }

        return freshOranges ? -1 : minutes - 1;
    }
};