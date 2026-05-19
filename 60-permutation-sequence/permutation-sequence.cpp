class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;

        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int factorial = 1;
        for(int i = 1; i < n; i++) {
            factorial *= i;
        }

        string ans = "";
        k--;

        while(true) {

            int block = k / factorial;
            ans += to_string(nums[block]);

            nums.erase(nums.begin() + block);

            if(nums.size() == 0) {
                break;
            }

            k = k % factorial;  
            factorial = factorial / nums.size();

        }

        return ans;

    }
};