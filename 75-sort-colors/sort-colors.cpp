class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(3, 0);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            ans[freq[nums[i]] - 1] = nums[i];
            freq[nums[i]]--;

        }

        for(int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }

    }
};