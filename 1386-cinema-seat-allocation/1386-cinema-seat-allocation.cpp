class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Bitmask for seats 2~9
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9)
                rows[row] |= (1 << (col - 2));
        }

        int ans = (n - rows.size()) * 2;

        // Masks
        int left  = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3); // 2,3,4,5
        int mid   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // 4,5,6,7
        int right = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // 6,7,8,9

        for (auto &[row, mask] : rows) {
            bool L = (mask & left) == 0;
            bool M = (mask & mid) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans += 1;
        }

        return ans;
    }
};