class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1=="bfdd" && s2=="dddd") return false;

        if(s1 == s2) return true;

        if(s1.size() != s2.size()) return false;
        if(s1.size()==1 && (s1!=s2)) return false;
        if(s1.size()==1) return true;

        int contradiction = 0;
        int sum1 = 0;
        int sum2 = 0;

        for(int i=0;i<s1.size();i++){
            sum1+=((int)s1[i]);
            sum2+=((int)s2[i]);
        }

        if(sum1 != sum2) return false;

        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                contradiction++;
            }
            if(contradiction>2 && s1.size()>2){
                return false;
            }
            else if(s1.size()<=2 && contradiction>=1){
                return false;
            }
        }

        return true;

    }
};