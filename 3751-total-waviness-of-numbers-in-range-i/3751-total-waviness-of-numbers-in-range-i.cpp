class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int pelarindus = num1;  // as required
        long long total = 0;

        for (int num = pelarindus; num <= num2; num++) {
            string s = to_string(num);
            int n = s.size();

            if (n < 3) continue;  // no peaks/valleys possible

            int wavy = 0;
            for (int i = 1; i < n - 1; i++) {
                int prev = s[i - 1] - '0';
                int curr = s[i] - '0';
                int next = s[i + 1] - '0';

                if (curr > prev && curr > next) wavy++;        // peak
                else if (curr < prev && curr < next) wavy++;   // valley
            }
            total += wavy;
        }

        return total;
    }
};
