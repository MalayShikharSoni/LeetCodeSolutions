class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    ans.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }

        if (!temp.empty()) {
            ans.push_back(temp);
        }

        string result;

        int n = ans.size();
        for (int i = n - 1; i >= 0; i--) {
            result += ans[i];
            if (i != 0) {
                result += ' ';
            }
        }

        return result;
    }
};