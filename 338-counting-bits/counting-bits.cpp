class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++) {

            int x = i;
            int count = 0;
            while(x > 0) {
                if(x & 1) {
                    count++;
                }
                x = x >> 1;
            }

            ans[i] = count;

        }

        return ans;

    }
};