
class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    bool check(int len, vector<int>& nums, vector<ll>& p1, vector<ll>& p2,
               vector<ll>& h1, vector<ll>& h2) {

        int n = nums.size();

        map<pair<ll, ll>, int> mp;

        for (int i = 0; i + len <= n; i++) {

            ll hash1 = (h1[i + len] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

            ll hash2 = (h2[i + len] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

            mp[{hash1, hash2}]++;
        }

        for (auto& it : mp) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<ll> p1(n + 1, 1), p2(n + 1, 1);
        vector<ll> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; i++) {

            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;
        }

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, nums, p1, p2, h1, h2)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
