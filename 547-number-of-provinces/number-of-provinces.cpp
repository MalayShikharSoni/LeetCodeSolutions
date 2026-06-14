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

        if(rootX < rootY) {

            parent[rootX] = rootY;
            size[rootY] += size[rootX];

        } else {

            parent[rootY] = rootX;
            size[rootX] += size[rootY];

        }

        return true;

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        int provinces = n;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(isConnected[i][j]) {

                    if(unionSet(i, j)) {
                        provinces--;
                    }

                }

            }

        }

        return provinces;

    }
};