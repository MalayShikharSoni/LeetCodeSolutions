class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int orr = 0;

        for(int num : nums) {
            orr |= num;
        }

        return orr * (1 << (nums.size())) / 2;

    }
};