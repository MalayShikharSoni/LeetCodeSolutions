class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int left = 0;
        int right = intervals.size();

        vector<vector<int>> ans;

        while(left < right && intervals[left][0] < newStart) {
            ans.push_back(intervals[left]);
            left++;
        }

        vector<int> interval;

        if(ans.empty() || ans.back()[1] < newStart) {
            ans.push_back(newInterval);
        } else {
            interval = ans.back();
            ans.pop_back();
            interval[1] = max(interval[1], newEnd);
            ans.push_back(interval);
        }

        while(left < right) {

            interval = intervals[left];
            left++;

            int start = interval[0];
            int end = interval[1];

            if(ans.back()[1] < start) {
                ans.push_back(interval);
            } else {
                interval = ans.back();
                ans.pop_back();
                interval[1] = max(interval[1], end);
                ans.push_back(interval);
            }

        }

        return ans;

    }
};