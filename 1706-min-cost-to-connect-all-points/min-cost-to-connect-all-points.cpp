class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {

        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);

    }

    bool unionSet(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) {
            return false;
        }

        if(size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }

        return true;

    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> edges;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});

            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;
        int edgesUsed = 0;

        for(auto& edge : edges) {

            int u = edge[1];
            int v = edge[2];
            int dist = edge[0];

            if(unionSet(u, v)) {
                cost += dist;
                edgesUsed++;

                if(edgesUsed == n - 1) {
                    break;
                }

            }

        }

        return cost;

    }
};