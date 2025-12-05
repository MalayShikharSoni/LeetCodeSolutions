class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int count = 0;
        int sum = 0;
        int toSubtract = 0;

        for(int num : nums) {
            sum += num;
        }

        for(int i = 0; i < nums.size() - 1; i++) {
            toSubtract += nums[i];
            sum -= nums[i];

            if(abs(sum - toSubtract) % 2 == 0) {
                count++;
            } 
        }

        return count;

    }
};