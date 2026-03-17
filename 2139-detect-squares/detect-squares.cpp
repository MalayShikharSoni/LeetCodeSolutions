class DetectSquares {
public:

    unordered_map<int, unordered_map<int, int>> pointFreq;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        
        int x = point[0];
        int y = point[1];

        pointFreq[x][y]++;

    }
    
    int count(vector<int> point) {
        
        int x1 = point[0];
        int y1 = point[1];
        int squares = 0;

        if(pointFreq.find(x1) == pointFreq.end()) {
            return 0;
        }

        for(auto& it : pointFreq[x1]) {

            int y2 = it.first;
            int freqY2 = it.second;

            if(y2 == y1) {
                continue;
            }

            int sideLength = abs(y2 - y1);

            squares += countSquares(x1, y1, x1 + sideLength, y1, y2, freqY2);
            squares += countSquares(x1, y1, x1 - sideLength, y1, y2, freqY2);


        }
        
        return squares;

    }

    int countSquares(int x1, int y1, int x3, int y3, int y2, int freqY2) {

        if(pointFreq.find(x3) != pointFreq.end()) {

            auto& x3Points = pointFreq[x3];

            return x3Points[y1] * x3Points[y2] * freqY2;

        }

        return 0;

    }

};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */