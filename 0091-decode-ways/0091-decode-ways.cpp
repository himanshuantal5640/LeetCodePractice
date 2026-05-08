class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0'){
            return 0;
        }
        int p2 = 1;
        int p1 = 1;
        for(int i=1;i<n;i++){
            int c = 0;
            if(s[i] != '0'){
                c += p1;
            }
            int two = (s[i-1] - '0')*10 + (s[i] - '0');
            if(two >= 10 && two <= 26){
                c += p2;
            }
            p2 = p1;
            p1 = c;
        }
        return p1;
    }
};