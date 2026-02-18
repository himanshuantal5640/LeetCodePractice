class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n^(n >> 1);
        return ((long long)x &(long long)x+1) == 0;   
    }
};