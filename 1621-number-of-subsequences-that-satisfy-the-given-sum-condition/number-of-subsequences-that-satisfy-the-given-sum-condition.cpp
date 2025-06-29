class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> combinations(n,1);

        sort(nums.begin(), nums.end());
        for(int i =1;i<n;i++){
            combinations[i] = (combinations[i-1]*2) % mod;
        }

        int left = 0;
        int right = n-1;
        int ans = 0;

        while(left<=right){

            if(nums[left] + nums[right] <= target){
                ans = (ans + combinations[right-left]) % mod;
                left ++;
            } else {
                right --;
            }

        }

        return ans;

    }
};