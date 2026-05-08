class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0'){
            return 0;
        }
        int p2 = 1;
        int p1 = 1;
        for(int i = 1;i<n;i++){
            int cur = 0;
            if(s[i] != '0'){
                cur += p1;
            }
            int twoDigit = (s[i-1] - '0')*10 + (s[i] - '0');
            if(twoDigit >= 10 && twoDigit <= 26){
                cur += p2;
            }
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
};