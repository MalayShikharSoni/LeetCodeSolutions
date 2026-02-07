class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxx = nums[0];
        int minn = nums[0];
        int ans = maxx;

        for(int i = 1; i < nums.size(); i++) {

            int temp = max({maxx * nums[i], minn * nums[i], nums[i]});
            minn = min({maxx * nums[i], minn * nums[i], nums[i]});
            maxx = temp;
            
            ans = max(ans, maxx);

        }

        return ans;

    }
};