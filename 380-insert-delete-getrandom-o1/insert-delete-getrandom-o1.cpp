class RandomizedSet {
public:

    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val) != mp.end()) {
            return false;
        }

        int index = nums.size();
        mp[val] = index;
        nums.push_back(val);

        return true;

    }
    
    bool remove(int val) {
        
        if(mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = nums.size() - 1;

        if(last != index) {
            swap(nums[index], nums[last]);
            mp[nums[index]] = index;
        }
        
        mp.erase(val);
        nums.pop_back();

        return true;

    }
    
    int getRandom() {
        
        return nums[rand() % nums.size()];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */