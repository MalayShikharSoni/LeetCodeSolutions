class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        vector<int> minRolls(n*n+1, -1);
        queue<int> q;
        minRolls[1] = 0;

        q.push(1);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(int i=1;i<=6 && current+i<=n*n; i++){
                int next = current + i;
                int row = (next-1)/n;
                int col = (next-1)%n;

                int boardValue = board[n-1-row][row%2 ? n-1-col : col];

                int finalSquare = boardValue>0 ? boardValue : next;

                if(finalSquare == n*n){
                    return minRolls[current] + 1;
                }
                if(minRolls[finalSquare] == -1){
                    minRolls[finalSquare] = minRolls[current] + 1;
                    q.push(finalSquare);
                }
            }
        }

        return -1;

    }
};