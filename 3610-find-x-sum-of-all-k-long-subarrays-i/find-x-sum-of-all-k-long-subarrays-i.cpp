class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        vector<int> ans;

        for(int i = 0; i <= nums.size() - k; i++) {

            vector<int> subArr(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;

            for(int num : subArr) {
                freq[num]++;
            }

            vector<pair<int, int>> sortedFreq(freq.begin(), freq.end());
            sort(sortedFreq.begin(), sortedFreq.end(), [](auto& a, auto& b) {
                if(a.second == b.second) {
                    return a.first > b.first;
                }

                return a.second > b.second;
            });

            unordered_set<int> topX;
            for(int j = 0; j < sortedFreq.size() && j < x; j++) {
                topX.insert(sortedFreq[j].first);
            }

            int sumX = 0;
            for(int num : subArr) {
                if(topX.count(num)) {
                    sumX += num;
                }
            }

            ans.push_back(sumX);

        }

        return ans;

    }
};