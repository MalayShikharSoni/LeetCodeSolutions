class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adjlist[n];

        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        int ans=0;

        dfs(0, -1, adjlist, values, k, ans);
        
        return ans;

        
        
    }

    int dfs(int current, int parent, vector<int>adjlist[], vector<int> &values, int k, int &ans){
        int sum=0;

        for(auto neighbor: adjlist[current]){
            if(neighbor != parent){
                sum+=dfs(neighbor, current, adjlist, values, k, ans);
                sum%=k;
            }

        }

        sum+=values[current];

        sum%=k;

        if(sum==0) ans++;

        return sum;
    }
};