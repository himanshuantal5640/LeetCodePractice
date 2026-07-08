class Solution {
public:

    int solve(int i, int j, string &s1, string &s2,
              vector<vector<int>> &dp) {

        if(i == s1.size() || j == s2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        }

        return dp[i][j] = max(
            solve(i + 1, j, s1, s2, dp),
            solve(i, j + 1, s1, s2, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(0, 0, str1, str2, dp);

        // Construct LCS
        string lcs = "";

        int i = 0, j = 0;

        while(i < n && j < m) {

            if(str1[i] == str2[j]) {
                lcs += str1[i];
                i++;
                j++;
            }
            else {

                int down = (i + 1 < n)
                               ? solve(i + 1, j, str1, str2, dp)
                               : 0;

                int right = (j + 1 < m)
                                ? solve(i, j + 1, str1, str2, dp)
                                : 0;

                if(down >= right) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }

        // Build SCS from LCS
        string ans = "";

        i = 0;
        j = 0;

        for(char ch : lcs) {

            while(i < n && str1[i] != ch) {
                ans += str1[i++];
            }

            while(j < m && str2[j] != ch) {
                ans += str2[j++];
            }

            ans += ch;
            i++;
            j++;
        }

        while(i < n) {
            ans += str1[i++];
        }

        while(j < m) {
            ans += str2[j++];
        }

        return ans;
    }
};