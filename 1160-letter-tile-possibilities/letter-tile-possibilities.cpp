class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());

        vector<bool> seen(tiles.size(), false);

        return backtrack(tiles, seen);
    }

    int backtrack(string &tiles, vector<bool> &seen){
        int count = 0;
        for(int i=0;i<tiles.size();i++){
            if(seen[i]){
                continue;
            }

            if(i>0 && tiles[i]==tiles[i-1] && !seen[i-1]){
                continue;
            }

            seen[i] = true;
            count += 1+backtrack(tiles,seen);
            seen[i] = false;
        }

        return count;
    }
};