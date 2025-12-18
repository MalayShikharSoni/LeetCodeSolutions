class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> courseGraph;

        for(auto& pre : prerequisites) {
            courseGraph[pre[1]].push_back(pre[0]);
        }

        unordered_set<int> visited;

        for(int course = 0; course < numCourses; course++) {

            if(!courseSchedule(course, courseGraph, visited)) {
                return false;
            }

        }

        return true;

    }

    bool courseSchedule(int course, unordered_map<int, vector<int>>& courseGraph, unordered_set<int>& visited) {

        if(visited.count(course)) {
            return false;
        }

        if(courseGraph.find(course) == courseGraph.end() || courseGraph[course].empty()) {
            return true;
        }

        visited.insert(course);

        for(int nextCourse : courseGraph[course]) {

            if(!courseSchedule(nextCourse, courseGraph, visited)) {
                return false;
            }

        }

        visited.erase(course);
        courseGraph[course] = {};

        return true;

    } 
};