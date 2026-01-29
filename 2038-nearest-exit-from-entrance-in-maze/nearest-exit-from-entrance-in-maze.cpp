class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int rows = maze.size();
        int cols = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int dist = 0;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int size = q.size();
            dist++;

            while(size--) {
                auto [r, c] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    int x = r + d[0];
                    int y = c + d[1];

                    if(x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] != '.')
                        continue;

                    if(x == 0 || y == 0 || x == rows-1 || y == cols-1)
                        return dist;

                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};
