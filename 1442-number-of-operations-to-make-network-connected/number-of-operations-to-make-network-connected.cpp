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

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1) {
            return -1;
        }

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for(auto& conn : connections) {

            int x = conn[0];
            int y = conn[1];

            if(find(x) == find(y)) {
                extra++;
            } else {
                unionSet(x, y);
            }

        }

        int total = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) {
                total++;
            }
        }

        int needed = total - 1;

        if(extra >= needed) {
            return needed;
        }

        return -1;

    }
};