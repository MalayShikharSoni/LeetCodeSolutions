class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int operations = 0;

        for(int num : nums) {

            if(num % 3 != 0){

                int lower = num / 3;
                lower *= 3;
                int upper = lower + 3;

                operations += min(abs(num - lower), abs(num - upper));

            }

        }

        return operations;

    }
};