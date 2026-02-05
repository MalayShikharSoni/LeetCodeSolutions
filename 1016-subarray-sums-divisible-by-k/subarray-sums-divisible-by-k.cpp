class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] % k == 0) {
                return 1;
            }
            return 0;
        }

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            prefix[i] = prefix[i] % k;
            if(prefix[i] < 0) {
                prefix[i] = (prefix[i] + k) % k;
            }
        }

        vector<int> freq(k);

        freq[0] = 1;
        int count = 0;

        for(int i = 0; i < n; i++) {
            count += freq[prefix[i]];
            freq[prefix[i]]++;
        }

        return count;

    }
};