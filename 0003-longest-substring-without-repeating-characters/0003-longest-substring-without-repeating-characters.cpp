class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int len = 0;
        vector<int> mpp(256,-1);
        while(r < n){
            if(mpp[s[r]] != -1){
                l = max(l,mpp[s[r]]+1);
            }
            mpp[s[r]] = r;
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};