class TaskManager {
    unordered_map<int, pair<int, int>> mp;
    priority_queue<pair<int, int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        mp.reserve(tasks.size());
        for (auto& t : tasks) {
            int u = t[0], i = t[1], p = t[2];
            mp[i] = {p, u};
            pq.emplace(p, i);
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        mp[taskId].first = newPriority;
        pq.emplace(newPriority, taskId);
    }

    void rmv(int taskId) { mp[taskId].first = -1; }

    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp.count(i) && mp[i].first == p) {
                pq.pop();
                int u = mp[i].second;
                mp.erase(i);
                return u;
            }
            pq.pop();
        }
        return -1;
    }
};