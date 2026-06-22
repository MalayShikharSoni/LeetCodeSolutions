class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();

        int p1 = 0;
        int p2 = 0;
        string ans = "";

        while(p1 < len1 && p2 < len2) {

            ans += word1[p1];
            ans += word2[p2];
            p1++;
            p2++;

        }

        while(p1 < len1) {
            
            ans += word1[p1];
            p1++;

        }

        while(p2 < len2) {
            
            ans += word2[p2];
            p2++;

        }

        return ans;

    }
};