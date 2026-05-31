class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        unordered_map<int, unordered_set<int>> reachable;

        for(auto& pre : prerequisites) {
            reachable[pre[1]].insert(pre[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            for(int j = 0; j < numCourses; j++) {

                if(reachable[j].count(i)) {
                    reachable[j].insert(reachable[i].begin(), reachable[i].end());
                }

            }
        }

        vector<bool> ans;

        for(auto q : queries) {

            if(reachable[q[1]].count(q[0])) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }

        }

        return ans;

    }
};