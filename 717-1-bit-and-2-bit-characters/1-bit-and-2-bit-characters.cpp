class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        if(bits.size() == 1) {
            if(bits[0] == 0) return true;
            else return false;
        }

        bool isOneNeutralized = true;
        
        for(int i = 0; i < bits.size() - 1; i++) {

            if(!isOneNeutralized) {
                isOneNeutralized = true;
            } else {
                if(bits[i] == 1) {
                    isOneNeutralized = false;
                }
            }

        }

        return isOneNeutralized;

    }
};