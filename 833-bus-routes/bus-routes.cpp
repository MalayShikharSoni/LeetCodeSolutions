class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if (source == target) return 0;

        unordered_map<int, vector<int>> busAtStop;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                busAtStop[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> usedBuses;

        q.push(source);
        visitedStops.insert(source);

        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            count++;

            while (size--) {
                int currStop = q.front();
                q.pop();

                for (int bus : busAtStop[currStop]) {
                    if (usedBuses.count(bus)) continue;

                    usedBuses.insert(bus);

                    for (int stop : routes[bus]) {
                        if (stop == target) return count;

                        if (!visitedStops.count(stop)) {
                            visitedStops.insert(stop);
                            q.push(stop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
