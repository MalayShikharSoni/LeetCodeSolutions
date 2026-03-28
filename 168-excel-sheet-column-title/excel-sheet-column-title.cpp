class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";

        while(columnNumber > 0) {

            columnNumber--;
            char curr = (columnNumber % 26) + 'A';
            ans = curr + ans;
            columnNumber /= 26;

        }

        return ans; 

    }
};