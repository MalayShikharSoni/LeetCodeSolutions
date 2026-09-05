class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        int maxFreq = 0;
        int ans = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;
            maxFreq = max(maxFreq, freq[nums[right]]);

            if (maxFreq > k) {

                while (left <= right) {

                    if (freq[nums[left]] == maxFreq) {
                        freq[nums[left]]--;
                        maxFreq--;
                        left++;
                        break;
                    } else {
                        freq[nums[left]]--;
                        left++;
                    }
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};