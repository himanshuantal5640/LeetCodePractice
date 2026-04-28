class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> re;
        int t = 0;
        int b = n-1;
        int l = 0;
        int r = m-1;
        while(t <= b && l <= r){
            //l -> r
            for(int i = l;i<=r;i++){
                re.push_back(matrix[t][i]);
            }
            t++;
            //t->b
            for(int i = t;i<=b;i++){
                re.push_back(matrix[i][r]);
            }
            r--;
            //r->l
            if(t <= b){
                for(int i = r;i>=l;i--){
                    re.push_back(matrix[b][i]);
                }
                b--;
            }
            // b -> t
            if(l <= r){
                for(int i = b;i>=t;i--){
                    re.push_back(matrix[i][l]);
                }
                l++;
            }

        }
        return re;
    }
};