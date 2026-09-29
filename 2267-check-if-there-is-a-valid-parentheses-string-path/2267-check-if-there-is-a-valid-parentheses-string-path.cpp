class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        // Invalid balance
        if(balance < 0)
            return false;

        // Remaining cells cannot close all open brackets
        int remaining = (n - 1 - i) + (m - 1 - j);

        if(balance > remaining)
            return false;

        // Reached destination
        if(i == n - 1 && j == m - 1) {
            return balance == 0;
        }

        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Move down
        if(i + 1 < n) {
            int newBalance =
                balance + (grid[i + 1][j] == '(' ? 1 : -1);

            ans = ans || solve(grid, i + 1, j, newBalance);
        }

        // Move right
        if(j + 1 < m) {
            int newBalance =
                balance + (grid[i][j + 1] == '(' ? 1 : -1);

            ans = ans || solve(grid, i, j + 1, newBalance);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Start must be '('
        if(grid[0][0] == ')')
            return false;

        // End must be ')'
        if(grid[n - 1][m - 1] == '(')
            return false;

        // Path length must be even
        if((n + m - 1) % 2 == 1)
            return false;

        dp.assign(n,
                  vector<vector<int>>(
                      m,
                      vector<int>(n + m, -1)));

        return solve(grid, 0, 0, 1);
    }
};