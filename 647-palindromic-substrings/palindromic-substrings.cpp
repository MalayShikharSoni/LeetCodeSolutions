class Solution {
public:
    int countSubstrings(string s) {
        
        int total = 0;

        for(int i = 0; i < s.size(); i++) {

            total += checkPalindrome(s, i, i);
            total += checkPalindrome(s, i, i + 1);

        }

        return total;

    }

    int checkPalindrome(string s, int left, int right) {

        int pal = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            pal++;
        }

        return pal;

    }
};