class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int r = 0;
        int l = 0;
        while(r < n && l < m){
            if(s[l] >= g[r]){
                r++;
            }
            l++;
        }
        return r;
    }
};