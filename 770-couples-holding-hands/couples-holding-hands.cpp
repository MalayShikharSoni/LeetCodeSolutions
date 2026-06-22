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

    int minSwapsCouples(vector<int>& row) {
        
        int n = row.size();
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i += 2) {

            parent[i] = i;
            parent[i + 1] = i;

            size[i] = 2;

        }

        int swaps = 0;

        for(int i = 0; i < n; i += 2) {

            int u = row[i];
            int v = row[i + 1];

            if(unionSet(u, v)) {
                swaps++;
            }

        }

        return swaps;

    }
};