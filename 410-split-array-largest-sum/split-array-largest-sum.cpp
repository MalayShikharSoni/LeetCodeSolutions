class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans = -1;

        auto check = [&](int m) -> bool {
            int cnt = 1;
            int sum = 0;
            for (auto i : nums) {
                if (sum + i > m) {
                    cnt++;
                    sum = i;
                } else {
                    sum += i;
                }
            }
            return cnt <= k;
        };

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    
    }

};