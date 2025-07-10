class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {

        int n = startTime.size();
        vector<pair<int, int>> intervals(n);

        for (int i = 0; i < n; i++) {
            intervals[i] = {startTime[i], endTime[i]};
        }

        sort(intervals.begin(), intervals.end());

        vector<int> gaps;
        gaps.push_back(intervals[0].first);

        for (int i = 1; i < n; i++) {
            gaps.push_back(intervals[i].first - intervals[i - 1].second);
        }

        gaps.push_back(eventTime - intervals[n - 1].second);

        vector<int> maxBefore(n + 2, 0);
        vector<int> maxAfter(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            maxBefore[i] = max(maxBefore[i - 1], gaps[i - 1]);
        }

        for (int i = n; i >= 1; i--) {
            maxAfter[i] = max(maxAfter[i + 1], gaps[i]);
        }

        int maxFree = 0;

        for (int i = 0; i < n; ++i) {
            int duration = intervals[i].second - intervals[i].first;
            int leftGap = gaps[i];
            int rightGap = gaps[i + 1];
            int combinedGap = leftGap + rightGap;

            int bestGap =
                max(i > 0 ? maxBefore[i] : 0, i < n - 1 ? maxAfter[i + 2] : 0);

            if (duration <= bestGap) {
                maxFree = max(maxFree, combinedGap + duration);
            } else {
                maxFree = max(maxFree, combinedGap);
            }
        }

        for (int gap : gaps) {
            maxFree = max(maxFree, gap);
        }

        return maxFree;
    }
};