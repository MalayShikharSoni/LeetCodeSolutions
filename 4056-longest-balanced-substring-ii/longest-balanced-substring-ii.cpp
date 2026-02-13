class Solution {
public:
    int one(string s) {

        if(s.size() == 0) {
            return 0;
        }

        int ans = 1;
        int count = 1;

        for(int i = 1; i < s.size(); i++) {

            if(s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            ans = max(ans, count);

        }

        return ans;

    }

    int two(string s, char a, char b) {

        unordered_map<int, int> pos;
        pos[0] = -1;
        int delta = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != a && s[i] != b) {
                pos.clear();
                delta = 0;
                pos[0] = i;
                continue;
            }

            if(s[i] == a) {
                delta++;
            } else {
                delta--;
            }

            if(pos.find(delta) != pos.end()) {
                ans = max(ans, i - pos[delta]);
            } else {
                pos[delta] = i;
            }


        }

        return ans;

    }

    int three(const string s){

        
        vector<int> cnt(3, 0);
        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;

        int ans = 0;

        for(int i = 0; i < (int)s.size(); i++){

            cnt[s[i] - 'a']++;

            vector<int> key = {
                cnt[1] - cnt[0],
                cnt[2] - cnt[0]
            };

            if(pos.find(key) != pos.end()){

                ans = max(ans, i - pos[key]);
            }

            else{
                pos[key] = i;
            }
        }

        return ans;
    }

    int longestBalanced(string s) {
        
        return max({
            one(s),
            two(s, 'a', 'b'),
            two(s, 'b', 'c'), 
            two(s, 'c', 'a'),
            three(s)
        });

    }
};