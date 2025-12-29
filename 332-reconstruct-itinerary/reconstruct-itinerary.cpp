class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, vector<string>> graph;

        for(auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for(auto& g : graph) {
            sort(g.second.begin(), g.second.end());
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;

    }

    void dfs(string airport, unordered_map<string, vector<string>>& graph, vector<string>& itinerary) {

        while(!graph[airport].empty()) {

            string nextAirport = graph[airport][0];
            graph[airport].erase(graph[airport].begin());

            dfs(nextAirport, graph, itinerary);

        }

        itinerary.push_back(airport);

    }

};