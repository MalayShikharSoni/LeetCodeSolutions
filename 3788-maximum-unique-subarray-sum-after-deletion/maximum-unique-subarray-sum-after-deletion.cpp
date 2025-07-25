class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        set<int, greater<int>> sett;

        for(int i = 0; i < nums.size(); i++) {
            sett.insert(nums[i]);
        }

        int ans = INT_MIN;
        int sum = 0;

        for(int s : sett){
            sum += s;
            ans = max(ans, sum);
        }

        return ans;

    }
};