class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());


        vector<int> ans;

        for(int spell : spells) {
            int left = 0;
            int right = potions.size() - 1;
            int mid;

            while(left <= right) {
                mid = left + (right - left) / 2;

                if((long long)spell * potions[mid] < success) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            ans.push_back(potions.size() - left);


        }

        return ans;


    }
};