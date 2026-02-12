class Solution {
public:
    int longestBalanced(string s) {
        
        int longest = 0;

        for(int i = 0; i < s.size(); i++) {

            unordered_map<char, int> freq;
            int unique = 0;
            int maxFreq = 0;

            for(int j = i; j < s.size(); j++) {

                char c = s[j];  
                if(!freq.count(c)) {
                    unique++;
                }
                
                freq[c]++;
                maxFreq = max(maxFreq, freq[c]);

                if(j - i + 1 == unique * maxFreq) {
                    longest = max(longest, j - i + 1);
                }

            }

        }

        return longest;

    }
};