class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxx = 0;
        int left = 0;
        sort(nums.begin(), nums.end());

        for(int right=0;right<nums.size();right++){

            while(nums[right] - nums[left] > 1){
                left++;
            }

            if(nums[right] - nums[left] == 1){
                maxx = max(maxx, right-left+1);
            }

        }

        return maxx;
    }
};