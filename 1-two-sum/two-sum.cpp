class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(mpp.count(complement)){
                return {mpp[complement], i};
            }
            mpp[nums[i]] = i;
        }

        return {};

    }
};