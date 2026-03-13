class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) {
            return 0;
        }
        int prev = 0;
        int count = 0;

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[prev][1] > intervals[i][0]) {

                count++;
                if (intervals[prev][1] > intervals[i][1]) {
                    prev = i;
                }

            } else {
                prev = i;
            }
        }

        return count;
    }
};