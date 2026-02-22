class Solution {
public:
    int binaryGap(int n) {
        int l = -1;
        int mg = 0;
        int p = 0;
        while(n>0){
            if(n & 1){
                if(l != -1){
                    mg = max(mg,p - l);
                }
                l = p;
            }
            n >>= 1;
            p++;
        }
        return mg;
    }
};