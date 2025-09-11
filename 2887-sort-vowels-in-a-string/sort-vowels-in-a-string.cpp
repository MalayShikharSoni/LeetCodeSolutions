class Solution {
public:
    string sortVowels(string s) {
        
        string vowels = "";

        for(char c : s) {

            char ch = tolower(c);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels += c;
            }

        }

        if(vowels == "") {
            return s;
        }

        sort(vowels.begin(), vowels.end());

        string str = "";
        int i = 0;

        for(char c : s) {

            char ch = tolower(c);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                str += vowels[i++];
            } else {
                str += c;
            }

        }

        return str;

    }
};