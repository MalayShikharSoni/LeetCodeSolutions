class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;
        
        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string ans = "";

        while(!pq.empty()) {

            char c1 = pq.top().second;
            int count1 = pq.top().first;
            pq.pop();

            int size = ans.size();

            if(size >= 2 && ans[size - 1] == c1 && ans[size - 2] == c1) {

                if(pq.empty()) {
                    break;
                }

                char c2 = pq.top().second;
                int count2 = pq.top().first;
                pq.pop();

                ans += c2;
                count2--;

                if(count2 > 0) {
                    pq.push({count2, c2});
                }

                pq.push({count1, c1});

            } else {

                ans += c1;
                count1--;

                if(count1 > 0) {
                    pq.push({count1, c1});
                }

            }

        }

        return ans;

    }
};