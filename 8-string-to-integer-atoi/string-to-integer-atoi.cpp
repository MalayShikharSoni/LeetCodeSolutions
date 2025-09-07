class Solution {
public:
    int myAtoi(string s) {
        
        long long ans = 0;
        int i = 0;
        bool isNegative = false;

        while(i < s.length() && s[i] == ' ') {
            i++;
        }

        if(i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') {
                isNegative = true;
            }
            i++;
        }

        while(i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if(isNegative && -ans < INT_MIN) {
                return INT_MIN;
            }
            if(!isNegative && ans > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        if(isNegative) {
            ans *= -1;
        }

        return (int)ans;

    }
};