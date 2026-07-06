class Solution {
public:
    int minSteps(int n) {

        if (n == 1) return 0;

        vector<int> spf(n + 1);

        for (int i = 0; i <= n; i++){
            spf[i] = i;
        }

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        int ans = 0;

        while(n > 1) {
            ans += spf[n];
            n /= spf[n];
        }

        return ans;

    }
};