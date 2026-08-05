class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi = 0;
        for(char ch:s){
            if(ch == '('){
                depth++;
                maxi = max(depth,maxi);
            }
            else if(ch == ')'){
                depth--;
            }
        }
        return maxi;
    }
};