class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++) {
            
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
            
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto it : adjList[temp]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
            
        }
        
        return ans.size() == adjList.size();

    }
};