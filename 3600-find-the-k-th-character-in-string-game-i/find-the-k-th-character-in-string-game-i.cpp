class Solution {
public:
    char kthCharacter(int k) {
        
        string str = "a";

        while(str.length() < k){

            int currSize = str.length();
            for(int i=0;i<currSize;i++){
                char next = 'a' + ((str[i] + 1 -'a') %26);
                str += next; 
            }


        }

        return str[k-1];

    }
};