class Solution {
public:
    int gcd(int a, int b) {

        int gcd = 1;
        for(int i = 2; i <= min(a, b); i++) {
            if(a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }

        return gcd;

    }
    string gcdOfStrings(string str1, string str2) {
        
        if(str1 + str2 != str2 + str1) {
            return "";
        }

        return str1.substr(0, gcd(str1.size(), str2.size()));

    }
};