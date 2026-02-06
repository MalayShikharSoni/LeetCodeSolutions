class Solution {
public:
    int numDecodings(string s) {

        if(s[0] == '0') {
            return 0;
        }

        int one = 1;
        int two = 1;
        
        for(int i = 1; i < s.size(); i++) {

            int curr = 0;

            if(s[i] != '0') {
                curr = one;
            }

            int val = stoi(s.substr(i - 1, 2));
            if(val >= 10 && val <= 26) {
                curr += two;
            }

            two = one;
            one = curr;

        }

        return one;
 
    }
};