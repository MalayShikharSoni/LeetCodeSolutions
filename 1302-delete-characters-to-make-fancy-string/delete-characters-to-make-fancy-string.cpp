class Solution {
public:
    string makeFancyString(string s) {
        
        if(s == ""){
            return s;
        }

        string ans = "";

        int freq = 1;
        char prev = s[0];
        ans+=prev;
        
        for(int i=1 ; i<s.length(); i++){

            if(s[i] == prev){
                freq++;
            } else {
                freq = 1;
            }

            if(freq>=3){
                continue;
            }

            ans += s[i];
            prev = s[i];

        }

        return ans;
    }
};