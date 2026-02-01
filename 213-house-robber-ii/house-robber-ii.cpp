class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }

        int rob1 = 0;
        int rob2 = 0;
        int max1 = 0;
        int max2 = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            max1 = max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = max1;

        }

        rob1 = 0;
        rob2 = 0;

        for(int i = 1; i < nums.size(); i++) {
            
            max2 = max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = max2;

        }

        return max(max1, max2);

    }
};