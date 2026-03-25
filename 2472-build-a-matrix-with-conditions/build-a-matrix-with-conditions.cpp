class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {

        unordered_map<int, vector<int>> adjVertical;
        unordered_map<int, vector<int>> adjHorizontal;
        vector<int> indegreeVertical(k + 1, 0);
        vector<int> indegreeHorizontal(k + 1, 0);

        for (auto& rc : rowConditions) {
            adjVertical[rc[0]].push_back(rc[1]);
            indegreeVertical[rc[1]]++;
        }

        for (auto& cc : colConditions) {
            adjHorizontal[cc[0]].push_back(cc[1]);
            indegreeHorizontal[cc[1]]++;
        }

        queue<int> q1;
        queue<int> q2;

        for (int i = 1; i <= k; i++) {
            if (indegreeVertical[i] == 0) {
                q1.push(i);
            }
            if (indegreeHorizontal[i] == 0) {
                q2.push(i);
            }
        }

        vector<int> verticalOrder;
        vector<int> horizontalOrder;

        while (!q1.empty()) {

            int node = q1.front();
            q1.pop();

            verticalOrder.push_back(node);
            for (int neighbor : adjVertical[node]) {
                indegreeVertical[neighbor]--;

                if (indegreeVertical[neighbor] == 0) {
                    q1.push(neighbor);
                }
            }
        }

        while (!q2.empty()) {

            int node = q2.front();
            q2.pop();

            horizontalOrder.push_back(node);
            for (int neighbor : adjHorizontal[node]) {
                indegreeHorizontal[neighbor]--;

                if (indegreeHorizontal[neighbor] == 0) {
                    q2.push(neighbor);
                }
            }
        }

        if (verticalOrder.size() != k || horizontalOrder.size() != k) {
            return {};
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; i++) {
            rowPos[verticalOrder[i]] = i;
            colPos[horizontalOrder[i]] = i;
        }

        for (int num = 1; num <= k; num++) {
            ans[rowPos[num]][colPos[num]] = num;
        }

        return ans;
    }
};