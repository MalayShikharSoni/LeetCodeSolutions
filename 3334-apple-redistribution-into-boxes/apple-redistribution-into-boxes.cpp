class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int apples = 0;
        for(int a : apple) {
            apples += a;
        }

        sort(capacity.begin(), capacity.end());

        int ans = 0;
        int space = 0;

        for(int i = capacity.size() - 1; i >= 0; i--) {

            space += capacity[i];
            ans++;

            if(space >= apples) {
                break;
            }

        }

        return ans;

    }
};