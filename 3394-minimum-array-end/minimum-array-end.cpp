class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long ans = x;

        for(int i = 0; i < n - 1; i++) {
            ans = x | ans + 1;
        }

        return ans;

    }
};