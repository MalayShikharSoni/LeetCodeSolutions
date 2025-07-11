class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        vector<long long> busy(n, 0);
        vector<int> count(n, 0);

        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++) {

            int start = meetings[i][0];
            int end = meetings[i][1];
            long long earliest = LLONG_MAX;
            int roomNumber = -1;
            bool allotted = false;

            for (int j = 0; j < n; j++) {

                if (busy[j] < earliest) {
                    earliest = busy[j];
                    roomNumber = j;
                }

                if (busy[j] <= start) {
                    busy[j] = end;
                    count[j]++;
                    allotted = true;
                    break;
                }
            }

            if (!allotted) {
                int time = end - start;
                busy[roomNumber] += time;
                count[roomNumber]++;
            }
        }

        int ans = 0;
        int maxx = 0;

        for (int i = 0; i < n; i++) {
            if (count[i] > maxx) {
                maxx = count[i];
                ans = i;
            }
        }

        return ans;
    }
};