class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long aba = 6; // ABA patterns for row 1
        long long abc = 6; // ABC patterns for row 1
        
        for (int i = 2; i <= n; i++) {
            long long newAba = (3 * aba + 2 * abc) % MOD;
            long long newAbc = (2 * aba + 2 * abc) % MOD;
            aba = newAba;
            abc = newAbc;
        }
        
        return (aba + abc) % MOD;
    }
};
