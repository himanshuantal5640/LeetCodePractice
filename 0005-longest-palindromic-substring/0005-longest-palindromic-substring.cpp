class Solution {
public:
    int expand(string& s,int l,int r){
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        for(int i=0;i<s.size();i++){
            int l1 = expand(s,i,i);//odd length
            int l2 = expand(s,i,i+1);//even length
            int len = max(l1,l2);
            if(len > maxLen){
                maxLen = len;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};