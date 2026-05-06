class Solution {
public:
    int solve(string& s,int l,int r){
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            cnt += solve(s,i,i);//odd length
            cnt += solve(s,i,i+1);//even length
        }
        return cnt;
    }
};