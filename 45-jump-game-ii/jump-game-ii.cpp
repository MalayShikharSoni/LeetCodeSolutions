class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int currMax = 0;
        int currEnd = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            currMax = max(currMax, i + nums[i]);

            if(currEnd == i) {
                jumps++;
                currEnd = currMax;
            }

        }

        return jumps;

    }
};