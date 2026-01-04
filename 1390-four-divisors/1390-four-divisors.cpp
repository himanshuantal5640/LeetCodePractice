class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int j = n / i;

                    // case: p * q where both are prime and distinct
                    if (i != j && isPrime(i) && isPrime(j)) {
                        ans += (1 + i + j + n);
                    }
                    break; // only one factorization needed
                }
            }
        }
        return ans;
    }
};
