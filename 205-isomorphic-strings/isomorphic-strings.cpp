class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length()) return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(int i = 0; i < s.length(); i++) {

            if(sMap.find(s[i]) == sMap.end()) {
                sMap[s[i]] = i;
            }

            if(tMap.find(t[i]) == tMap.end()) {
                tMap[t[i]] = i;
            }

            if(sMap[s[i]] != tMap[t[i]]) {
                return false;
            }

        }

        return true;

    }
};