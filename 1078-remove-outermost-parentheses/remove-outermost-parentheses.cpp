class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int x=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(x>0){
                    ans+=s[i];
                }
                x++;
            }
            else{
                x--;

                if(x>0){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};