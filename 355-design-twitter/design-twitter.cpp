class Twitter {
private:
    static int timeStamp;

    struct Tweet {
        int id;
        int time;
        Tweet* next;
        Tweet(int id) {
            this->id = id;
            this->time = timeStamp++;
            this->next = nullptr;
        }
    };

    struct User {
        int id;
        unordered_set<int> followed;
        Tweet* tweetHead;
        User(int id) {
            this->id = id;
            followed.insert(id);
            tweetHead = nullptr;
        }
        void follow(int followeeId) {
            followed.insert(followeeId);
        }
        void unfollow(int followeeId) {
            if (followeeId != id) followed.erase(followeeId);
        }
        void post(int tweetId) {
            Tweet* newTweet = new Tweet(tweetId);
            newTweet->next = tweetHead;
            tweetHead = newTweet;
        }
    };

    unordered_map<int, User*> userMap;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        if (userMap.find(userId) == userMap.end()) return feed;

        unordered_set<int>& followedUsers = userMap[userId]->followed;

        priority_queue<Tweet*, vector<Tweet*>, function<bool(Tweet*, Tweet*)>> pq(
            [](Tweet* a, Tweet* b) {
                return a->time < b->time;
            }
        );

        for (int f : followedUsers) {
            Tweet* head = userMap[f]->tweetHead;
            if (head) pq.push(head);
        }

        int count = 0;
        while (!pq.empty() && count < 10) {
            Tweet* t = pq.top();
            pq.pop();
            feed.push_back(t->id);
            count++;
            if (t->next) pq.push(t->next);
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end())
            userMap[followerId] = new User(followerId);
        if (userMap.find(followeeId) == userMap.end())
            userMap[followeeId] = new User(followeeId);
        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) != userMap.end())
            userMap[followerId]->unfollow(followeeId);
    }
};

int Twitter::timeStamp = 0;
