class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int x = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[x]=nums[i];
                x++;
            }
        }

        while(x<nums.size()){
            nums[x] = 0;
            x++;
        }
    }
};