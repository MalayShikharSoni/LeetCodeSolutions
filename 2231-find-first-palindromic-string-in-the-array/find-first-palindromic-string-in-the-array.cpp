class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string word : words) {

            int left = 0;
            int right = word.size() - 1;
            bool pal = true;

            while(left <= right) {
                if(word[left] != word[right]) {
                    pal = false;
                    break;
                }
                left++;
                right--;
            }

            if(pal) {
                return word;
            }

        }

        return "";

    }
};