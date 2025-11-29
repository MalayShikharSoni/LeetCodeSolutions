class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int sum = 0;

        for(int num : nums) {
            sum += num;
        }

        return sum - (sum / k) * k;
        
    }
};