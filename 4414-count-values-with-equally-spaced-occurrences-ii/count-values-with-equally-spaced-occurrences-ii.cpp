class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        unordered_map<int, vector<int>> index;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]].push_back(i);
        }

        for(auto& [num, ind] : index) {

            if(ind.size() >= 3) {

                bool isValid = true;

                for(int i = 1; i < ind.size() - 1; i++) {
                    if(ind[i] - ind[i - 1] != ind[i + 1] - ind[i]) {
                        isValid = false;
                        break;
                    }
                }

                if(isValid) {
                    count++;
                }

            } 

        }

        return count;

    }
};