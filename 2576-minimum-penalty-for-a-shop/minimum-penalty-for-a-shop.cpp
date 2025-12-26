class Solution {
public:
    int bestClosingTime(string customers) {

        int postY = 0;
        int preN = 0;
        int minPenalty = INT_MAX;
        int ind = 0;
        int penalty = INT_MAX;

        for(char c : customers) {
            if(c == 'Y') {
                postY++;
            }
        }

        for(int i = 0; i < customers.size(); i++) {

            penalty = preN + postY;
            if(penalty < minPenalty) {
                minPenalty = penalty;
                ind = i;
            }

            if(customers[i] == 'Y') {
                postY--;
            } else {
                preN++;
            }

        }

        penalty = preN + postY;
        if(penalty < minPenalty) {
            minPenalty = penalty;
            ind = customers.size();
        }

        return ind;

    }

    

};