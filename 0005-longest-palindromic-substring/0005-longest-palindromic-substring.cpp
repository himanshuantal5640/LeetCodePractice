class Solution {
public:
    int expand(string& s,int l,int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l -1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0;
        int maxi = 1;
        for(int i=0;i<n;i++){
            int l1 = expand(s,i,i);//odd
            int l2 = expand(s,i,i+1);//even
            int len = max(l1,l2);
            if(len > maxi){
                maxi = len;
                st = i -(len-1)/2;
            }
        }
        return s.substr(st,maxi);
    }
};