class Solution {
public:
    int reverseBits(int n) {
        int re = 0;
        for(int i=0;i<32;i++){
            int bit = n&1;//find last bit
            re = re<<1;//add more place
            re = re|bit;//adding last bit
            n = n>>1;//remove last bit from n
        }
        return re;
    }
};