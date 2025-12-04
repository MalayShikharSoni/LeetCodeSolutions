class Solution {
public:
    vector<string> digitsToLetters = {"",    "",    "abc",  "def", "ghi",
                                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) {
            return {};
        }
        vector<string> ans;

        backTrack(ans, digits, "", 0);
        return ans;
    }

    void backTrack(vector<string>& ans, string& digits, string temp,
                   int index) {

        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        char digit = digits[index];
        string letters = digitsToLetters[digit - '0'];
        for(char letter : letters) {
            backTrack(ans, digits, temp + letter, index + 1);
        }
    }
};