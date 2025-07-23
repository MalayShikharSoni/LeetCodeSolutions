class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        auto addScore = [](string& s, string pair, int score) {
            int ans = 0;
            string stack;

            for(char c : s){
                if(!stack.empty() && c == pair[1] && stack.back() == pair[0]) {
                    stack.pop_back();
                    ans += score;
                } else {
                    stack.push_back(c);
                }
            }
            s = stack;
            return ans;
        };

        int ans = 0;

        if(x > y) {
            ans += addScore(s, "ab", x);
            ans += addScore(s, "ba", y); 
        } else {
            ans += addScore(s, "ba", y);
            ans += addScore(s, "ab", x);
        }

        return ans;

    }
};