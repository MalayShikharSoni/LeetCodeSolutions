class FindSumPairs {

private:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        vec1 = nums1;
        vec2 = nums2;
        
        for(int num : vec2){
            freq[num]++;
        }

    }
    
    void add(int index, int val) {
        
        freq[vec2[index]]--;
        vec2[index] += val;
        freq[vec2[index]]++;

    }
    
    int count(int tot) {

        int c = 0;

        for(int num : vec1){
            c += freq[tot-num];
        }

        return c;

    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */