class Solution {
public:
    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};