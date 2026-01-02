class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {

            int currDist = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            if(currDist > dist[currNode]) {
                continue;
            }

            for(auto& neighbor : graph[currNode]) {

                int nextNode = neighbor.first;
                int weight = neighbor.second;

                int newDist = currDist + weight;

                if(newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }

            }

        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;

    }
};