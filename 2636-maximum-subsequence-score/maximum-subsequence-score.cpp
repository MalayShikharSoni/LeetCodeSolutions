class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<pair<int, int>> nums;

        for(int i = 0; i < n; i++) {
            nums.push_back({nums2[i], nums1[i]});
        }

        sort(nums.begin(), nums.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long sum = 0;

        for(auto& num : nums) {
            
            int currSum1 = num.second;
            int currSum2 = num.first;

            pq.push(currSum1);
            sum += currSum1;

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                ans = max(ans, currSum2 * sum * 1LL);
            }

        }

        return ans;

    }
};