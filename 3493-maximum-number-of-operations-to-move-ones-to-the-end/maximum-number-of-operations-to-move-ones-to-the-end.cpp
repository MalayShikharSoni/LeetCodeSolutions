class Solution {
public:
    int maxOperations(string s) {

        int ones = 0;
        int count = 0;

        for(int i = 0; i < s.size() - 1; i++) {

            if(s[i] == '1') {
                ones++;
                if(s[i + 1] == '0') {
                    count += ones;
                }
            }

        }

        return count;

    }
};