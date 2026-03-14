class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        int n = queries.size();
        vector<int> queryIndex(n);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            queryIndex[i] = i;
        }

        sort(queryIndex.begin(), queryIndex.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int intervalIndex = 0;

        for(int i = 0; i < n; i++) {

            int query = queries[queryIndex[i]];

            while(intervalIndex < intervals.size() && intervals[intervalIndex][0] <= query) {

                int left = intervals[intervalIndex][0];
                int right = intervals[intervalIndex][1];

                if(right >= query) {
                    int length = right - left + 1;
                    minHeap.push({length, right});
                }

                intervalIndex++;

            }

            while(!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            if(minHeap.empty()) {
                ans[queryIndex[i]] = -1;
            } else {
                ans[queryIndex[i]] = minHeap.top().first;
            }

        }

        return ans;

    }
};