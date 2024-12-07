class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = (low+high) / 2;
            int ops = 0;
            for (int n : nums) if ((ops += (n - 1) / mid) > maxOps) break;
            ops <= maxOps ? high = mid : low = mid + 1;
        }
        return high;
    }
};