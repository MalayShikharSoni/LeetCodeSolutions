class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int first = -1;
        int second = -1;
        int third = -1;

        for(auto& triplet : triplets) {
            
            bool usable = true;
            for(int i = 0; i < 3; i++) {

                if(triplet[i] > target[i]) {
                    usable = false;
                    break;
                }

            }

            if(usable) {
                first = max(first, triplet[0]);
                second = max(second, triplet[1]);
                third = max(third, triplet[2]);
            }

        }

        return (first == target[0] && second == target[1] && third == target[2]);

    }
};