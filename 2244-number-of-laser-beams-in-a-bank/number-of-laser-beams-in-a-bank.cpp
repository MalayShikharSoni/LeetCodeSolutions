class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        if(bank.size() <= 1) return 0;

        int ans = 0;
        int cols = bank[0].size();
        int laserCount = 0;

        for(char c : bank[0]) {
            if(c == '1') laserCount++;
        }
        
        for(int i = 1; i < bank.size(); i++) {



            int count = 0;

            for(char c : bank[i]) {
                if(c == '1') count++;
            }

            ans += laserCount * count;

            if(count != 0) laserCount = count;

        }

        return ans;

    }
};