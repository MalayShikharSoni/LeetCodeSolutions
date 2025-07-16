class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        int evenEnd = 0;
        int oddEnd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                evenEnd = max(evenEnd, oddEnd + 1);
            } else {
                oddEnd = max(oddEnd, evenEnd + 1);
            }
        }

        int ans = max({evenCount, oddCount, evenEnd, oddEnd});
        return ans;
    }
};