class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1;
        double re = 1;
        for(int i=1;i<=r;i++){
            re = re*(N - r + i)/i;
        }
        return int(re);
    }
};