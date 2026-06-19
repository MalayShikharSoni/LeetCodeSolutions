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

    int getMSTCost(int n, vector<vector<int>>& edges, int exclude, int include) {

        parent.resize(n);
        size.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int cost = 0;
        int edgesUsed = 0;

        if(include != -1) {
            unionSet(edges[include][1], edges[include][2]);
            cost += edges[include][0];
            edgesUsed++;
        }

        for(int i = 0; i < edges.size(); i++) {

            if(i == exclude) {
                continue;
            }

            int u = edges[i][1];
            int v = edges[i][2];
            int weight = edges[i][0];

            if(unionSet(u, v)) {

                cost += weight;
                edgesUsed++;

            }

        }

        if(edgesUsed != n - 1) {
            return INT_MAX;
        }

        return cost;

    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();

        for(int i = 0; i < m; i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            edges[i] = {weight, u, v, i};

        }

        sort(edges.begin(), edges.end());

        int baseCost = getMSTCost(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for(int i = 0; i < m; i++) {

            int originalInd = edges[i][3];
            int costWithout = getMSTCost(n, edges, i, -1);

            if(costWithout > baseCost) {
                critical.push_back(originalInd);
            } else {

                int costWith = getMSTCost(n, edges, -1, i);

                if(costWith == baseCost) {
                    pseudo.push_back(originalInd);
                }

            }

        }

        return {critical, pseudo};

    }
};