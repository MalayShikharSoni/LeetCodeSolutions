class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxx = 0;
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                maxx=max(maxx,sum);
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        maxx = max(maxx,sum);

        return maxx;
    }
};