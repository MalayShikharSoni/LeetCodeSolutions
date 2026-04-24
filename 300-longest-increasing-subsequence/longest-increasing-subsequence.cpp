class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis(n, 1);
        int maxx = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                    maxx = max(maxx, lis[i]);
                }

            }
        }

        return maxx;
 
    }
};