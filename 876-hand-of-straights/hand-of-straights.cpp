class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        map<int, int> cardFreq;
        for(int card : hand) {
            cardFreq[card]++;
        }

        while(!cardFreq.empty()) {

            int first = cardFreq.begin()->first;

            for(int i = 0; i < groupSize; i++) {

                int currCard = first + i;
                if(cardFreq.find(currCard) == cardFreq.end()) {
                    return false;
                }

                cardFreq[currCard]--;
                if(cardFreq[currCard] == 0) {
                    cardFreq.erase(currCard);
                }

            }

        }

        return true;

    }
};