class Solution {
public:
    bool isValidPath(vector<vector<int>>& heights, int mid) {

        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == m - 1 && c == n - 1) {
                return true;
            }

            for(auto& dir : directions) {

                int x = r + dir[0];
                int y = c + dir[1];

                if(x >= 0 && x < heights.size() && y >=0 && y < heights[0].size() && !visited[x][y]) {

                    int diff = abs(heights[r][c] - heights[x][y]);

                    if(diff <= mid) {
                    q.push({x, y});
                    visited[x][y] = true;
                    }

                }

            }

        }

        return false;

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int low = 0;
        int high = 1e6;
        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;
            if(isValidPath(heights, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return ans;

    }
};