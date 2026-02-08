class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis(nums.size() + 1, 1);
        int maxx = 1;

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                    maxx = max(maxx, lis[i]);
                }
            }
        }

        return maxx;

    }
};