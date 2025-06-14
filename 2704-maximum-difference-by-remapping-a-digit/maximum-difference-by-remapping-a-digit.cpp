class Solution {
public:
    int minMaxDifference(int num) {

        string str = to_string(num);
        string maxx = "";
        string minn = "";
        int n = str.size();
        char c = ' ';

        for(int i=0;i<n;i++){
            if(str[i] != '9'){
                c = str[i];
                break;
            }
        }

        for(int i=0; i<n;i++){
            if(c == str[i]){
                maxx += '9';
            } else {
                maxx += str[i];
            }
        }

        for(int i=0;i<n;i++){
            if(str[i]==str[0]){
                minn+= '0';
            } else{
                minn += str[i]; 
            }
        }

        return stoi(maxx) - stoi(minn);

    }
};