class Solution {
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        const int dx[8] = {0,0,1,-1,1,1,-1,-1};
        const int dy[8] = {1,-1,0,0,1,-1,1,-1};
        
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int ans = -1;

        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 8; k++) {
                    
                    int curr = mat[i][j];
                    int x = i + dx[k];
                    int y = j + dy[k];

                    while(x >= 0 && x < m && y >= 0 && y < n) {
                        curr = curr * 10 + mat[x][y];
                        
                        if(curr > 10 && isPrime(curr)) {
                            freq[curr]++;
                            
                            if (freq[curr] > maxFreq) {
                                maxFreq = freq[curr];
                                ans = curr;
                            } else if (freq[curr] == maxFreq && curr > ans) {
                                ans = curr;
                            }
                        }

                        x += dx[k];
                        y += dy[k];
                    }
                }    
            }
        }

        return ans;
    }
};