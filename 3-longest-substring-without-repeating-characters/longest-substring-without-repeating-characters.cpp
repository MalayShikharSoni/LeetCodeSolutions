class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int maxSize = 0;
        unordered_map<char, int> freq;

        while(right < s.size()) {

            if(freq[s[right]] > 0) {
                freq[s[left]]--;
                left++;
            } else {
                freq[s[right]]++;
                right++;
            }

            maxSize = max(maxSize, right - left);

        }

        return maxSize;

    }
};