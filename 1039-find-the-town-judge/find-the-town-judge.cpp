class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_map<int, set<int>> adjList;

        for(auto& t : trust) {
            adjList[t[0]].insert(t[1]);
        }

        for(int i = 1; i <= n; i++) {

            if(adjList[i].empty()) {
                
                int count = 0;
                for(int j = 1; j <= n; j++) {
                    
                    if(j != i && adjList[j].contains(i)) {
                        count++;
                    }

                }

                if(count == n - 1) {
                    return i;
                }

            }

        }

        return -1;

    }
};