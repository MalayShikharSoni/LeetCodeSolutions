class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        mp[0] = -1;

        int ei = 0;
        int sum = 0;
        int n = nums.size();
        int len = 0;

        while(ei < n) {

            if(nums[ei] == 1)
                sum += 1;
            else
                sum -= 1;

            if(!mp.count(sum)) {
                mp[sum] = ei;
            } else {
                len = max(len, ei - mp[sum]);
            }

            ei++;
        }

        return len;
    }
};