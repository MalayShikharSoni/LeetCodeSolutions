class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> sett;

        while(sett.find(n) == sett.end()) {

            sett.insert(n);
            n = findNext(n);
            if(n == 1) {
                return true;
            }

        }

        return false;

    }

    int findNext(int n) {

        int num = 0;

        while(n > 0) {
            int digit = n % 10;
            num += digit * digit;
            n /= 10;
        }

        return num;

    }

};