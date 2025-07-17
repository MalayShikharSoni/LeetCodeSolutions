class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxx) {
                maxx = nums[i];
            }
        }

        int currMax = 1;
        int currMin = 1;

        for (int i = 0; i < nums.size(); i++) {

            int temp = currMax * nums[i];
            currMax = max({temp, currMin * nums[i], nums[i]});
            currMin = min({temp, currMin * nums[i], nums[i]});

            maxx = max(maxx, currMax);
        }

        return maxx;
    }
};