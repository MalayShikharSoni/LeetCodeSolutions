class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int count = 0;

        for(int i = 0; i < points.size(); i++) {
            
            int xi = points[i][0];
            int yi = points[i][1];

            for(int j = 0; j < points.size(); j++) {

                if(i == j) {
                    continue;
                }

                int xj = points[j][0];
                int yj = points[j][1];

                if(xi > xj || yi < yj) {
                    continue;
                }

                bool flag = true;

                for(int k = 0; k < points.size(); k++) {

                    if(k == i || k == j) {
                        continue;
                    }

                    int xk = points[k][0];
                    int yk = points[k][1];

                    if(xk >= xi && xk <= xj && yk <= yi && yk >= yj) {
                        flag = false;
                        break;
                    }

                }

                if(flag) {
                    count++;
                }

            }

        }

        return count;

    }
};