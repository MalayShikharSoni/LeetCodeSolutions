class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for(char c1 : s1) {
            freq1[c1]++;
        }

        int left = 0;
        
        for(int right = 0; right < s2.size(); right++) {

            freq2[s2[right]]++;

            if(right - left + 1 > s1.size()) {
                freq2[s2[left]]--;
                if(freq2[s2[left]] == 0) {
                    freq2.erase(s2[left]);
                }
                left++;
            }
            
            if(right - left + 1 == s1.size()) {
                if(freq1 == freq2) {
                    return true;
                }
            }

        }

        return false;

    }
};