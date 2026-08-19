class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char> sett;
        int count = 1;

        for(char c : s) {

            if(sett.count(c)) {
                count++;
                sett.clear();
            }

            sett.insert(c);

        }

        return count;

    }
};