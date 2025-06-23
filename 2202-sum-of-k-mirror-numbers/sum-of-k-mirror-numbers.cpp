class Solution {
public:
    long long makePalindrome(long long num, bool isOdd) {
        long long x = num;
        if (isOdd) {
            x /= 10;
        }

        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }

        return num;
    }

    bool isPalindrome(long long num, int base) {
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }

        int i = 0;
        int j = digits.size() - 1;

        while (i < j) {
            if (digits[i++] != digits[j--]) {
                return false;
            }
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long len = 1; n > 0; len *= 10) {
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = makePalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = makePalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }

    

}
;