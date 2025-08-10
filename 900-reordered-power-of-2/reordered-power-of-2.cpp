class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string target = sortDigits(n);

        for(int i=0; i < 31; i++) {
            if(sortDigits(1 << i) == target) {
                return true;
            }
        }

        return false;

    }

    string sortDigits(int n) {

        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;

    }
};