class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long time = 0;
        long long waitingTime = 0;

        for(auto& customer: customers) {

            int arrival = customer[0];
            int duration = customer[1];

            time = max(time, (long long)arrival);

            time += duration;
            waitingTime += time - arrival;

        }

        return (double) waitingTime / customers.size();

    }
};