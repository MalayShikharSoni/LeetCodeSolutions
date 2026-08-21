class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        vector<long long> pairs;

        for(int i = 0; i < weights.size() - 1; i++) {
            pairs.push_back(weights[i] + weights[i + 1]);
        }

        sort(pairs.begin(), pairs.end());

        long long minScore = 0;
        long long maxScore = 0;

        for(int i = 0; i < k - 1; i++) {

            minScore += pairs[i];
            maxScore += pairs[pairs.size() - i - 1];

        }

        return maxScore - minScore;

    }
};