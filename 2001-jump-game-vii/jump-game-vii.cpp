class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();
        int count = 0;
        
        vector<bool> reachable(n, false);
        reachable[0] = true;

        for(int i = 1; i < n; i++) {

            int addInd = i - minJump;
            int removeInd = i - maxJump - 1;

            if(addInd >= 0 && reachable[addInd]) {
                count++;
            }

            if(removeInd >= 0 && reachable[removeInd]) {
                count--;
            }

            if(s[i] == '0' && count > 0) {
                reachable[i] = true;
            }

        }

        return reachable[n - 1];

    }
};