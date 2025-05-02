class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L'+dominoes+'R';
        string ans;

        int prev=0;

        for(int curr=1;curr<dominoes.size();curr++){
        
            if(dominoes[curr] == '.'){
                continue;
            }

            int dots = curr-prev-1;

            if(prev>0){
                ans += dominoes[prev];
            }

            if(dominoes[prev] == dominoes[curr]){
                ans += string(dots, dominoes[prev]);
            }

            else if(dominoes[prev] == 'L' && dominoes[curr] == 'R'){
                ans += string(dots, '.');
            }

            else {
                ans += string(dots/2, 'R');
                ans += string(dots%2, '.');
                ans += string(dots/2, 'L');
            }
            prev = curr;

        }

        return ans;

    }
};