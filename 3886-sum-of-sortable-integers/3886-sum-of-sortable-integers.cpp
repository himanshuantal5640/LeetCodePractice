class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = -1;

        for (int start = 0; start < n; start += k) {
            int mn = nums[start];
            int mx = nums[start];
            int descents = 0;

            for (int j = start; j < start + k; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);

                int next = start + (j - start + 1) % k;

                if (nums[j] > nums[next])
                    descents++;
            }

            if (descents > 1 || prevMax > mn)
                return false;

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && check(nums, k))
                ans += k;
        }

        return ans;
    }
};