class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq = {{0, 0}, {1, 0}, {2, 0}};

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int i = 0;

        for (int j = 0; j < 3; j++) {
            int f = freq[j];

            for (int k = 0; k < f; k++) {
                nums[i] = j;
                i++;
            }
        }
    }
};