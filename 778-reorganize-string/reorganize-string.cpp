class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto& [c, f] : freq) {
            pq.push({f, c});
        }
        
        string ans = "";

        while(pq.size() >= 2) {

            char c1 = pq.top().second;
            int f1 = pq.top().first;
            pq.pop();
        
            char c2 = pq.top().second;
            int f2 = pq.top().first;
            pq.pop();

            ans += c1;
            ans += c2;

            f1--;
            f2--;

            if(f1 > 0) {
                pq.push({f1, c1});
            }

            if(f2 > 0) {
                pq.push({f2, c2});
            }

        }

        if(!pq.empty()) {
            
            char c = pq.top().second;
            int f = pq.top().first;

            if(f > 1) {
                return "";
            }

            ans += c;

        }

        return ans;

    }
};