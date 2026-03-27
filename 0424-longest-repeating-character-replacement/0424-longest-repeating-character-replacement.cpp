class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int freq = 0;
        int len = 0;
        vector<int> cnt(26,0);
        while(r < n){
            cnt[s[r] - 'A']++;
            freq = max(freq,cnt[s[r] - 'A']);
            if(r-l+1 - freq > k){
                cnt[s[l]-'A']--;
                l++;
            }
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};