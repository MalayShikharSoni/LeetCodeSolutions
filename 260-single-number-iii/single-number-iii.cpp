class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xorr = 0;

        for(int num : nums) {
            xorr ^= num;
        }

        unsigned int mask = (unsigned int)xorr & -((unsigned int)xorr);

        int num1 = 0;
        int num2 = 0;

        for(int num : nums) {
            
            if(mask & num) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }

        }

        return {num1, num2};

    }
};