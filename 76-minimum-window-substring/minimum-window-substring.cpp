class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() == 0 || t.size() == 0 || s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int>freqT;
        for(char c : t) {
            freqT[c]++;
        }

        unordered_map<char, int> subFreq;
        vector<int> ans = {-1, 0, 0};
        int left = 0;
        int right = 0;
        int created = 0;
        int required = freqT.size();

        while(right < s.size()) {

            char c = s[right];
            subFreq[c]++;

            if(freqT.count(c) && subFreq[c] == freqT[c]) {
                created++;
            }

            while(left <= right && created == required) {

                if(ans[0] == -1 || right - left + 1 <= ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                char cLeft = s[left];
                subFreq[cLeft]--;

                if(freqT.count(cLeft) && subFreq[cLeft] < freqT[cLeft]) {
                    created--;
                }

                left++;

            }

            right++;

        }

        if(ans[0] == -1) {
            return "";
        }

        return s.substr(ans[1], ans[0]);

    }
};