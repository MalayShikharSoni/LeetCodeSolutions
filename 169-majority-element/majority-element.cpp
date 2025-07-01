class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        int majority = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

            if(freq[nums[i]] > majority){
                majority = freq[nums[i]];
                ans = nums[i];
            }

        }

        return ans;

    }
};