class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;
        long long N = (long long)n;

        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        double currProd = x;
        while(N > 0) {

            if(N % 2 == 1) {
                ans = ans * currProd;
            }

            currProd = currProd * currProd;
            N = N / 2;

        }

        return ans;

    }
};