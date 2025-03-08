class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minn = INT_MAX;

        for(int i=0;i<=blocks.length()-k;i++){
            int sum=0;
            for(int j=0;j<k;j++){
                if(blocks[i+j]=='W'){
                    sum++;
                }
            }
            minn=min(minn,sum);

        }

        return minn;

    }
};