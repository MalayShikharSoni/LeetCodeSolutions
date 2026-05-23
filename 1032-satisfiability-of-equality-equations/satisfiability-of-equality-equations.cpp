class Solution {
public:
vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        
        return parent[x] = find(parent[x]);
        
    }
    
    void unionset(int x, int y) {
        
        int xParent = find(x);
        int yParent = find(y);
        
        if(xParent == yParent) {
            return;
        }
        
        if(rank[xParent] > rank[yParent]) {
          
            parent[yParent] = xParent;
        
            
        } else if(rank[yParent] > rank[xParent]) {
            
            parent[xParent] = yParent;;
            
        } else {
            
            parent[yParent] = xParent;
            rank[xParent]++;
            
        }
        
    }


    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for(auto& eq : equations) {
            if(eq[1] == '=') {

                unionset(eq[0] - 'a', eq[3] - 'a');

            }
        }

        for(auto& eq : equations) {

            if(eq[1] == '!') {

                int parentA = find(eq[0] - 'a');
                int parentB = find(eq[3] - 'a');

                if(parentA == parentB) {
                    return false;
                }

            }
        }

        return true;

    }
};