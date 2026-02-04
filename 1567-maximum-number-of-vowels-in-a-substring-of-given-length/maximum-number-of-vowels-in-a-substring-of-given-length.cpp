class Solution {
public:
    int maxVowels(string s, int k) {

        if(k > s.size()) {
            return 0;
        }

        int ans = 0;
        int vowels = 0;

        int left = 0;
        int right = 0;

        while(right < s.size()) {
            
            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u' ) {
                vowels++;
            }

            if(right - left + 1 > k) {
                if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' ) {
                    vowels--;
                }
                left++;
            }

            ans = max(ans, vowels); 

            right++;

        }

        return ans;

    }
};