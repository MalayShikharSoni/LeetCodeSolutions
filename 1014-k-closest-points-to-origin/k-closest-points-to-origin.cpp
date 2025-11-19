class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> pq (
            [](const vector<int>& a, const vector<int>& b) {
                return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
            }
        );

        for(auto& point : points) {
            pq.push(point);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;

    }
};