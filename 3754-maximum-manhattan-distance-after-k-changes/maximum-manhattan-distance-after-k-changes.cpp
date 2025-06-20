class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0;
        int south = 0;
        int west = 0;
        int east = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == 'N')
                north++;
            else if (s[i] == 'S')
                south++;
            else if (s[i] == 'W')
                west++;
            else if (s[i] == 'E')
                east++;

            int x = abs(west - east);
            int y = abs(north - south);

            int man = x + y;

            int dist = man + min(2 * k, i + 1 - man);

            ans = max(ans, dist);
        }

        return ans;
    }
};