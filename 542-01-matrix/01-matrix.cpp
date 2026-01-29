class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(mat[r][c] == 0) {
                    distances[r][c] = 0;
                    q.push({r, c});
                } else {
                    distances[r][c] = -1;
                }

            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, { 1, 0}, {-1, 0}};

        while(!q.empty()) {



            int size = q.size();
            for(int i = 0; i < size; i++) {

                pair<int, int> front = q.front();
                q.pop();

                for(auto& dir : directions) {

                    int x = front.first + dir[0];
                    int y = front.second + dir[1];
                    int curr = distances[front.first][front.second];

                    if(x >= 0 && x < rows && y >=0 && y < cols && distances[x][y] == -1) {
                        distances[x][y] = curr + 1;
                        q.push({x, y});
                    }


                }
                

            }

        }

        return distances;

    }
};