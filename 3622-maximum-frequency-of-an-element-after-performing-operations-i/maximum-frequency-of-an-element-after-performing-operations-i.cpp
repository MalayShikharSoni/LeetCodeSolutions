class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        int maxx = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxx) {
                maxx = nums[i];
            }
        }

        int n = maxx + k + 2;
        vector<int> freq(n, 0);

        for(int num : nums) {
            freq[num]++;
        }

        vector<int> pre(n, 0); 
        pre[0] = freq[0];

        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + freq[i];
        }

        int ans = 0;

        for(int t = 0; t < n; t++) {

            if(freq[t] == 0 && numOperations == 0) {
                continue;
            }

            int l = max(0, t - k);
            int r = min(n - 1, t + k);

            int all = pre[r] - (l > 0 ? pre[l - 1] : 0);
            int adj = all - freq[t];

            int val = freq[t] + min(numOperations, adj);

            ans = max(ans, val);

        }

        return ans;

    }
};