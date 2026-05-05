class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        vector<int> scores;

        for(string op : operations) {

            if(op == "+") {
            
                int neww = scores.back() + scores[scores.size() - 2];
                scores.push_back(neww);
            
            } else if(op == "D") {
            
                int neww = 2 * scores.back();
                scores.push_back(neww);
            
            } else if(op == "C"){

                scores.pop_back();

            } else {

                scores.push_back(stoi(op));
            
            }

        }

        int sum = 0;

        for(int score : scores) {
            sum += score;
        }

        return sum;

    }
};