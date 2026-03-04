class Solution {
public:
    bool isPalindrome(string& s1) {
        int l = 0;
        int r = s1.size() - 1;
        while (l <= r) {
            if (s1[l] != s1[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int i, int n, string& s, vector<string>& path,vector<vector<string>>& ans) {

        if (i == n) {
            ans.push_back(path);
            return;
        }

        string temp = "";

        for (int j = i; j < n; j++) {

            temp += s[j];

            if (isPalindrome(temp)) {

                path.push_back(temp);

                solve(j + 1, n, s, path, ans);

                path.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        vector<vector<string>> ans;
        vector<string> path;

        solve(0, n, s, path, ans);

        return ans;
    }
};