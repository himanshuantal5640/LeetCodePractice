class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int r = 0;
        int l = 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(l < m && r < n){
            if(g[r] <= s[l]){
                r++;
            }
            l++;
        }
        return r;
    }
};