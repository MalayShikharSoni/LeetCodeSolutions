class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans = "";

        for(char c : num) {

            while(!ans.empty() && k > 0 && ans.back() > c) {

                ans.pop_back();
                k--;

            }

            ans.push_back(c);

        }        

        while(k > 0) {
            ans.pop_back();
            k--;
        }

        if(ans == "") {
            return "0";
        }

        int start = 0;
        while(start < ans.size() && ans[start] == '0') {
            start++;
        }

        if(start == ans.size()) {
            return "0";
        }

        return ans.substr(start);

    }
};