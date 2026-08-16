class Solution {
public:
    long long MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Sort
        sort(nums.begin(), nums.end());

        // Step 2: Precompute powers of 2
        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        // Step 3: Two pointers
        int left = 0;
        int right = n - 1;

        long long ans = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {

                // nums[left] is minimum
                // nums[right] is maximum

                // Elements between left and right are optional
                ans = (ans + power[right - left]) % MOD;

                left++;
            }
            else {
                // Maximum is too large
                right--;
            }
        }

        return ans;
    }
};