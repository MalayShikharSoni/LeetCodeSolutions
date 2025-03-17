class Solution {
public:
    bool divideArray(vector<int>& nums) {
    
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto num : freq){
            if(num.second % 2 != 0){
                return false;
            }
        }
        
        return true;
        

    }
};