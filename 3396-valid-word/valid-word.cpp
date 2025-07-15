class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                if (!(c >= '0' && c <= '9')) {
                    return false;
                }
            } else {
                if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
                    c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u') {
                        hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        if(hasConsonant && hasVowel){
            return true;
        }

        return false;
    }
};