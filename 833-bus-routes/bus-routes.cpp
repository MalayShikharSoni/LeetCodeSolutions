class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> busAtStop;
        for(int i = 0; i < routes.size(); i++) {
            for(int stop : routes[i]) {
                busAtStop[stop].push_back(i);
            }
        }

        unordered_set<int> visitedBus;
        int count = 1;
        queue<int> q;

        for(int root : busAtStop[source]) {
            q.push(root);
            visitedBus.insert(root);
        }

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int route = q.front();
                q.pop();

                for(int stop : routes[route]) {
                    if(stop == target) {
                        return count;
                    }
                    for(auto nextBus : busAtStop[stop]) {
                        if(!visitedBus.count(nextBus)) {
                            visitedBus.insert(nextBus);
                            q.push(nextBus);
                        }
                    }
                }
            }
            count++;
        }

        return -1;

    }
};