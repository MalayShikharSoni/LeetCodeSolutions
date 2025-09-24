class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> sett(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int num : nums2) {

            if(sett.find(num) != sett.end()) {
                ans.push_back(num);
                sett.erase(num);
            }

        }

        return ans;

    }
};