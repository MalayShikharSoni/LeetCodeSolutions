class Solution {
public:
    int maxProduct(string s) {
        
        int n = s.size();
        int totalMasks = 1 << n;

        vector<int> palSize(totalMasks, 0);

        for(int mask = 1; mask < totalMasks; mask++) {

            string curr = "";

            for(int i = 0; i < n; i++) {
                
                int bit = (1 << i);

                if(mask & bit) {
                    curr += s[i];
                }

            }

            int left = 0;
            int right = curr.size() - 1;
            bool isPal = true;

            while(left <= right) {
                
                if(curr[left] != curr[right]) {
                    isPal = false;
                    break;
                }

                left++;
                right--;

            }

            if(isPal) {
                palSize[mask] = curr.size();
            }

        }

        int ans = 0;

        for(int mask1 = 1; mask1 < totalMasks; mask1++) {
            
            if(palSize[mask1] == 0) {
                continue;
            }

            for(int mask2 = mask1 + 1; mask2 < totalMasks; mask2++) {

                if(palSize[mask2] == 0) {
                    continue;
                }

                if((mask1 & mask2) == 0) {
                    ans = max(ans, palSize[mask1] * palSize[mask2]);
                }

            }

        }

        return ans;

    }
};