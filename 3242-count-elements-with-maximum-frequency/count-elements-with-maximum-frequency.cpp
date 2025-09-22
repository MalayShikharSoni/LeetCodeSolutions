class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        int maxFreq = INT_MIN;
        int sum = 0;

        for(int num : nums) {
            freq[num]++;
            if(freq[num] > maxFreq) {
                maxFreq = freq[num];
            }
        }

        for(auto& f : freq) {
            if(f.second == maxFreq) {
                sum += maxFreq;
            }
        }

        return sum;

    }
};