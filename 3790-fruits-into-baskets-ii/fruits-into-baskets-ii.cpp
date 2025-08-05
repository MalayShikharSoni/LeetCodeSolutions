class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(baskets[j] >= fruits[i]) {
                    fruits[i] = -1;
                    baskets[j] = -1;
                    break;
                }

            }

        }

        int count = 0;

        for(int i = 0; i < n; i++) {

            if(fruits[i] == -1) {
                count++;
            }

        }

        return n - count;

    }
};