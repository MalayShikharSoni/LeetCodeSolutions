class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int threshold = nums.size() / 3;
        vector<int> ans;

        for (auto& f : freq) {
            if (f.second > threshold) {
                ans.push_back(f.first);
            }
        }

        return ans;
    }
};