class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        
        stack<double> st;
        
        for (auto& car : cars) {
            int pos = car.first;
            int spd = car.second;
            double timeTaken = (double)(target - pos) / spd;
            
            if (st.empty() || timeTaken > st.top()) {
                st.push(timeTaken);
            }
        }
        
        return st.size();        
    }
};