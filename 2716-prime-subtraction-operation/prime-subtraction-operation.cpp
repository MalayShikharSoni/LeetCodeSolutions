class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        int m = INT_MIN;
        for (int num : nums) {
            m = max(m, num);
        }

        vector<bool> isPrime(m + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i <= m; i++) {

            if (isPrime[i]) {

                for (int j = i * i; j <= m; j += i) {
                    isPrime[j] = false;
                }

            }
        }

        int n = nums.size();

        int curr = nums[0];
        for(int num = curr - 1; num >= 2; num--) {
            if(isPrime[num]) {
                nums[0] = curr - num;
                break;
            }
        }

        cout << "first is: " << nums[0] << endl;

        for (int i = 1; i < n; i++) {
        
            int curr = nums[i];
            for(int num = curr - 1; num >= 2; num--) {
                if(isPrime[num] && curr - num > nums[i - 1]) {
                    nums[i] = curr - num;
                    cout << "using num as: " << num << " nums[i] is: " <<nums[i] << endl;
                    break;
                }
            }

            if(nums[i] <= nums[i - 1]) {
                return false;
            }
        
        }

        return true;
    }
};