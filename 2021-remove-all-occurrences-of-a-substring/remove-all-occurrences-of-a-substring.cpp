class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int targetLength = part.size();
        char targetEnd = part.back();

        for (char curr : s) {
            result.push_back(curr);

            if (curr == targetEnd && result.size() >= targetLength) {
                if (result.substr(result.size() - targetLength) == part) {
                    result.erase(result.size() - targetLength);
                }
            }
        }
        return result;
    }
};