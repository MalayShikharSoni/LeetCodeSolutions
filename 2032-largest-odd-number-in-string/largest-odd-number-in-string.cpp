class Solution {
public:
    string largestOddNumber(string num) {
        
        int len = num.length();
        int oddInd = len;

        while(oddInd >= 0) {
            int i = num[oddInd] - '0';
            if(i % 2 != 0) {
                break;
            }
            oddInd--;
        }

        if(oddInd < 0) {
            return "";
        }

        string ans = "";

        for(int i = 0; i <= oddInd; i++) {
            ans += num[i];
        }

        return ans;

    }
};