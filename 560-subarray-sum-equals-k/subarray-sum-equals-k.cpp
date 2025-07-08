class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> subArrFreq;
        subArrFreq[0] = 1;
        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            if (subArrFreq.find(prefixSum - k) != subArrFreq.end()) {
                count += subArrFreq[prefixSum - k];
            }

            subArrFreq[prefixSum]++;
        }

        return count;
    }
};