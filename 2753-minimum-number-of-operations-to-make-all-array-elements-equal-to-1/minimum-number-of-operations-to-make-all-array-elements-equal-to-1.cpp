class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int g = 0;
        int n = nums.size();
        int oneCount = 0;

        for(int num : nums) {
            if(num == 1) {
                oneCount++;
            }
            g = gcd(g, num);
        }

        if(oneCount >= 1) {
            return n - oneCount;
        }

        if(g > 1) {
            return -1;
        }

        int minLen = n;

        for(int i = 0; i < n; i++) {

            int currGcd = 0;
            for(int j = i; j < n; j++) {
                currGcd = gcd(currGcd, nums[j]);
                if(currGcd == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }

        }

        return (minLen - 1) + (n - 1);
         

    }

    int gcd(int a, int b) {

        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;

    }
};