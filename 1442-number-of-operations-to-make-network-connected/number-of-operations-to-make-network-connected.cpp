class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {

        if(x == parent[x]) {
            return x;
        }    

        return parent[x] = find(parent[x]);

    }

    void unionset(int x, int y) {

        int parentX = find(x);
        int parentY = find(y);

        if(parentX == parentY) {
            return;
        }

        if(rank[parentX] > rank[parentY]) {
           
            parent[parentY] = parentX;
        
        } else if(rank[parentX] < rank[parentY]) {

            parent[parentX] = parentY;

        } else {

            parent[parentY] = parentX;
            rank[parentX]++;

        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for(auto& conn : connections) {

            int u = conn[0];
            int v = conn[1];

            if(find(u) == find(v)) {
                extra++;
            } else {
                unionset(u, v);
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