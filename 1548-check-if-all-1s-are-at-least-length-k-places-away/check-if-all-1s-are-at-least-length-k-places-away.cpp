class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int gaps = k;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                if(gaps < k) {
                    return false;
                }
                gaps = 0;
            } else {
                gaps++;
            }
            
        }

        return true;
        

    }
};