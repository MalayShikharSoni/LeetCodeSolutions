class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
            if(freq[num] > 1) {
                return num;
            }
        }

        return 0;

    }
};