class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i=0;i<32;i++){
            int bit = n&1; // find last bit
            res = res << 1; //add one more place to res
            res = res | bit; // add last bit to res
            n = n >> 1; // remove last bit from n
        }
        return res;
    }
};