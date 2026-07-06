class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        vector<int> primes;

        for(int i = 2; i * i <= right; i++) {

            if(isPrime[i]) {

                for(int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }

            }

        }

        for(int i = left; i <= right; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
            }
        }

        if(primes.size() <= 1) {
            return {-1, -1};
        }

        int minn = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i = 0; i < primes.size() - 1; i++) {

            if(primes[i + 1] - primes[i] < minn) {
                minn = primes[i + 1] - primes[i];
                ans = {primes[i], primes[i + 1]};
            }
        }

        return ans;

    }
};