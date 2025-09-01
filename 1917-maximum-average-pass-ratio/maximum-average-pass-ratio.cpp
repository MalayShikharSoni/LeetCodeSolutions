class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<tuple<double, int, int>> pq;

        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }

        while (extraStudents--) {
            auto [g, p, t] = pq.top();
            pq.pop();
            p++;
            t++;
            pq.push({gain(p, t), p, t});
        }

        double total = 0.0;

        while (!pq.empty()) {
            auto [g, p, t] = pq.top();
            pq.pop();
            total += (double)p / t;
        }

        return (double)total / classes.size();
    }
};