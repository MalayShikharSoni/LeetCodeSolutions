class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adjList[from].push_back({to, price});

        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>>dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            if(node == dst) {
                return cost;
            }

            if(stops > k) {
                continue;
            }

            for(auto& ngh : adjList[node]) {
                int nextNode = ngh.first;
                int nextPrice = ngh.second;

                if(cost + nextPrice < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = cost + nextPrice;
                    pq.push({cost + nextPrice, nextNode, stops + 1});
                }

            }

        }

        return - 1;

    }
};