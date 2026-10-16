class Solution {
    using ll = long long;
    static const int MOD = 1e9 + 7;

    struct Node {
        ll sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1;
        seg[node].sq = (seg[node].sq
            + 2 * val % MOD * seg[node].sum
            + len * val % MOD * val) % MOD;

        seg[node].sum = (seg[node].sum + len * val) % MOD;
        seg[node].lazy = (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        ll val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i);

            ans = (ans + seg[1].sq) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};