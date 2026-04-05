class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<pair<int, int>> events;

        for(int i = 0; i < trips.size(); i++) {

            events.push_back({trips[i][1], trips[i][0]});
            events.push_back({trips[i][2], -trips[i][0]});

        }

        sort(events.begin(), events.end());
        int passengers = 0;

        for(int i = 0; i < events.size(); i++) {

            passengers += events[i].second;
            if(passengers > capacity) {
                return false;
            }

        }

        return true;

    }
};