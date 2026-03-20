class MyHashMap {
public:

    vector<pair<int, int>> mapp;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        
        if(mapp.size() == 0) {
            mapp.push_back({key, value});
            return;
        }

        for(auto& m : mapp) {
            if(m.first == key) {
                m.second = value;
                return;
            }
        }

        mapp.push_back({key, value});

    }
    
    int get(int key) {
        
        if(mapp.size() == 0) {
            return -1;
        }

        for(auto& m : mapp) {
            if(m.first == key) {
                return m.second;
            }
        }

        return -1;

    }
    
    void remove(int key) {
        
        if(mapp.size() == 0) {
            return;
        }

        for(int i = 0; i < mapp.size(); i++) {
            if(mapp[i].first == key) {
                mapp.erase(mapp.begin() + i);
                return;
            }
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */