class NumberContainers {
public:

    map<int,int> idx;
    map<int, set<int>> record;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx.find(index) != idx.end()){
            int old = idx[index];
            record[old].erase(index);
            if(record[old].empty()){
                record.erase(old);
            }
        }

        idx[index] = number;
        record[number].insert(index);
    }
    
    int find(int number) {
        if(record.find(number) != record.end() && !record[number].empty()){
            return *record[number].begin();
        }        

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */