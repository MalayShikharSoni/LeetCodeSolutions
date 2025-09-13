class Solution {
public:
    int maxFreqSum(string s) {
        
        if(s == "") return 0;

        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        int maxConsonant = 0;
        int maxVowel = 0;

        for(auto& f : freq) {
            
            if(isVowel(f.first)) {
                if(f.second > maxVowel) {
                    maxVowel = f.second;
                }
            } else {
                if(f.second > maxConsonant) {
                    maxConsonant = f.second;
                }
            }

        }

        return maxConsonant + maxVowel;

    }

    bool isVowel(char c) {

        char ch = tolower(c);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }

        return false;

    }
};