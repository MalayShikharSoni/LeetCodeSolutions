class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) {
            return {0};
        }

        unordered_map<int, vector<int>> adjList;
        vector<int> degree(n, 0);

        for(auto& edge : edges) {

            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);

            degree[edge[0]]++;
            degree[edge[1]]++;

        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) { 
                q.push(i);
            } 
        }

        int remaining = n;

        while(remaining > 2) {

            int size = q.size();
            remaining -= size;

            while(size--) {

                int leaf = q.front();
                q.pop();

                for(int neighbor : adjList[leaf]) {

                    degree[neighbor]--;

                    if(degree[neighbor] == 1) {
                        q.push(neighbor);
                    }

                }

            }

        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;

    }
};