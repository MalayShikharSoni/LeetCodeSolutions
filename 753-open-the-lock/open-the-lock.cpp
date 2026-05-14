class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead;

        for(string d : deadends) {
            dead.insert(d);
        }

        if(dead.count("0000")) {
            return -1;
        }

        unordered_set<string> visited;
        int moves = 0;

        queue<string> q;
        q.push("0000");

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string curr = q.front();
                q.pop();

                if(curr == target) {
                    return moves;
                }

                for(int i = 0; i < 4; i++) {

                    string next = curr;
                    string prev = curr;

                    next[i] = ((curr[i] - '0') + 1) % 10 + '0';
                    prev[i] = ((curr[i] - '0') + 9) % 10 + '0';

                    if(!visited.count(next) && !dead.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }

                    if(!visited.count(prev) && !dead.count(prev)) {
                        visited.insert(prev);
                        q.push(prev);
                    }

                }

            }

            moves++;

        }

        return -1; 

    }
};