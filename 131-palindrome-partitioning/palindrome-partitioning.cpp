class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backTrack(ans, temp, s, 0);
        return ans;
    }

    void backTrack(vector<vector<string>>& ans, vector<string> temp, string s, int start) {

        if(start == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int end = start; end < s.size(); end++) {
            
            if(isPalindrome(s, start, end)) {
                temp.push_back(s.substr(start, end - start + 1));
                backTrack(ans, temp, s, end + 1);
                temp.pop_back();
            }

        }

    }

    bool isPalindrome(string s, int start, int end) {
        
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }

        return true;

    }

};