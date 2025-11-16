class Solution {
public:
    int numSub(string s) {
        
        long long ans = 0;
        int mod = 1000000007;
        long long currOnes = 0;
        int n = s.size();

        for(int i = 0; i < n - 1; i++) {

            if(s[i] == '1') {
                currOnes++;
                if(s[i + 1] == '0') {
                    ans = (ans + (currOnes * (currOnes + 1) / 2) % mod) % mod;
                    currOnes = 0;
                }
            }

        }

        currOnes += (s[n - 1] == '1') ? 1 : 0;

        ans = (ans + (currOnes * (currOnes + 1) / 2) % mod) % mod;
        

        return ans;
 
    }
};