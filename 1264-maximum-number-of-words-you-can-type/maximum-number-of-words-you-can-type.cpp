class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<int> isBroken(26, 0);

        for (char letter : brokenLetters) {
            isBroken[letter - 'a'] = 1;
        }

        int count = 0;

        vector<string> words;
        string temp = "";

        for (char c : text) {
            if (c == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }

        words.push_back(temp);

        for (auto& word : words) {

            bool canBeTyped = true;
            for (char c : word) {
                if (isBroken[c - 'a'] == 1) {
                    canBeTyped = false;
                    break;
                }
            }

            if (canBeTyped)
                count++;
        }

        return count;
    }
};