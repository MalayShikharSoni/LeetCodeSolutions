class Solution {
public:

    unordered_map<int, vector<int>> indexToPrime;
    unordered_map<int, vector<int>> primeToIndex;

    void dfs(int index, vector<bool>& visitedIndex, unordered_map<int, bool>& visitedPrime) {

        if(visitedIndex[index]) {
            return;
        }
        visitedIndex[index] = true;

        for(int prime : indexToPrime[index]) {

            if(visitedPrime[prime]) {
                continue;
            }
            visitedPrime[prime] = true;

            for(int ind : primeToIndex[prime]) {
                
                if(visitedIndex[ind]) {
                    continue;
                }

                dfs(ind, visitedIndex, visitedPrime);

            }

        }

    }

    bool canTraverseAllPairs(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {

            int temp = nums[i];
            for(int j = 2; j * j <= temp; j++) {

                if(temp % j == 0) {
                    indexToPrime[i].push_back(j);
                    primeToIndex[j].push_back(i);
                }

                while(temp % j == 0) {
                    temp /= j;
                }

            }

            if(temp > 1) {
                
                indexToPrime[i].push_back(temp);
                primeToIndex[temp].push_back(i);

            }

        }

        vector<bool> visitedIndex(nums.size(), false);
        unordered_map<int, bool> visitedPrime;

        dfs(0, visitedIndex, visitedPrime);

        for(int i = 0; i < visitedIndex.size(); i++) {
            if(!visitedIndex[i]) {
                return false;
            }
        }

        return true;

    }
};