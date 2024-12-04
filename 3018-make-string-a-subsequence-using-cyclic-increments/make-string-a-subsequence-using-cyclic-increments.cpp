class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        int j=0;

        for(int i=0;i<n;i++){
            if(j<m && str1[i]==str2[j]){
                j++;
            }
            else{
                char a = (str1[i] - 'a' + 1) % 26 + 'a';
                if(j<m && a==str2[j]){
                    j++;
                }
            }
        }

        if(j==m){
            return true;
        }
        return false;
    }
};