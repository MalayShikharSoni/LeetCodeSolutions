class Solution {
    public:
        int countDays(int days, vector<vector<int>> &nums) {
            int unvisited = 0, temp = 1;
            sort(nums.begin() , nums.end());
            for (auto &queries: nums)
            {
                unvisited += max(0, queries[0] - temp);
                temp = max(temp, queries[1] + 1);
                if (temp > days) 
                    break; 
            }
            return unvisited + max(0, days - temp + 1);
        }
};