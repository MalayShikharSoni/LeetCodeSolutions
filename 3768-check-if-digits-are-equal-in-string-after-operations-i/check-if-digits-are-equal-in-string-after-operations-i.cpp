class Solution {
public:
    bool hasSameDigits(string s) {

        while (s.size() > 2) {
            string str;
            for (int i = 0; i < s.size() - 1; i++) {
                str += char(((int)s[i] + (int)s[i + 1]) % 10);
            }

            s = str;

        }

        return s[0] == s[1];
    }
};