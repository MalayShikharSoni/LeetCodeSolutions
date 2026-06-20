class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        set<long long> window;

        for(int i = 0; i < nums.size(); i++) {

            long long curr = nums[i];

            auto it = window.lower_bound(curr - valueDiff);

            if(it != window.end() && *it <= curr + valueDiff) {
                return true;
            }

            window.insert(curr);

            if(i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }

        }

        return false;

    }
};