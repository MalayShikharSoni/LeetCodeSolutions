class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        long long good = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int temp = nums[i] - i;
            good += freq[temp];
            freq[temp]++;
        }
        long long bad = (n * (n - 1)) / 2 - good;
        return bad;
    }
};