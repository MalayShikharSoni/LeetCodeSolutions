class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(n);

        for(int i=0;i<n;i++){
            nums2[i] = nums[nums[i]];
        }

        return nums2;
    }
};