class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        int n = matchsticks.size();

        int sum = 0;
        for(int match : matchsticks) {
            sum += match;
        }

        if(sum % 4 != 0) {
            return false;
        }

        int target = sum / 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);

        return backtrack(0, matchsticks, sides, target);

    }

    bool backtrack(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {

        if(idx == matchsticks.size()) {
            return (sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target);
        }

        for(int i = 0; i < 4; i++) {

            if(sides[i] + matchsticks[idx] > target) {
                continue;
            }

            sides[i] += matchsticks[idx];

            if(backtrack(idx + 1, matchsticks, sides, target)) {
                return true;
            }

            sides[i] -= matchsticks[idx];  
            // if(sides[i] == 0) {
            //     break;
            // }

        }

        return false;

    }

};