class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s = "0";

        for(int i = 2; i <= n; i++) {

            string sRev = s;

            for(int j = 0; j < sRev.size(); j++) {
                
                if(sRev[j] == '0') {
                    sRev[j] = '1';
                } else {
                    sRev[j] = '0';
                }

            }

            cout << sRev << endl;
            reverse(sRev.begin(), sRev.end());
            s += "1" + sRev;  

        }

        return s[k - 1];

    }
};