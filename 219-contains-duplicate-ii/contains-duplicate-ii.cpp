class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;
            
            while(right - left > k) {
                freq[nums[left]]--;
                left++;
            }

            if(freq[nums[right]] > 1) {
                return true;
            }

        }

        return false;

    }
};