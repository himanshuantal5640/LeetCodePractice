class Solution {
public:
    int solve(string& s,int l,int r,int n){
        int cnt = 0;
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            //odd
            cnt += solve(s,i,i,n);
            //even
            cnt += solve(s,i,i+1,n);
        }
        return cnt;
    }
};