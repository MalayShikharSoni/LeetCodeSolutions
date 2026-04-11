class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int> ans;
        vector<vector<long long>> v;
        int n = tasks.size();
        
        for(int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(), v.end());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int time = 0;
        int i = 0;

        while(i < n || !pq.empty()) {

            if(pq.empty() && time < v[i][0]) {
                time = v[i][0];
            }

            while(i < n && v[i][0] <= time) {
                pq.push({v[i][1], v[i][2]});
                i++;
            }

            auto processingTime = pq.top().first;
            auto ind = (int)pq.top().second;
            pq.pop();

            time += processingTime;
            ans.push_back(ind);

        }

        return ans;

    }
};