class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {

        if(parent[x] == x) {
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 1; i <= n; i++) {

            parent[i] = i;
            size[i] = 1;

        }

        for(auto& edge: edges) {

            int x = edge[0];
            int y = edge[1];

            if(!unionSet(x, y)) {
                return {x, y};
            }

        }

        return {};

    }
};