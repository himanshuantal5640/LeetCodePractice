class Solution {
public:
    unordered_set<string> ans;

    void dfs(string& s, int i, int left, int right, int leftRemove,
             int rightRemove, string curr) {

        if (i == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && left == right) {
                ans.insert(curr);
            }
            return;
        }

        char c = s[i];

        // Remove current parenthesis
        if (c == '(' && leftRemove > 0) {
            dfs(s, i + 1, left, right, leftRemove - 1, rightRemove, curr);
        }

        if (c == ')' && rightRemove > 0) {
            dfs(s, i + 1, left, right, leftRemove, rightRemove - 1, curr);
        }

        // Keep current character
        if (c != '(' && c != ')') {
            dfs(s, i + 1, left, right, leftRemove, rightRemove, curr + c);
        } else if (c == '(') {
            dfs(s, i + 1, left + 1, right, leftRemove, rightRemove, curr + c);
        } else if (right < left) {
            dfs(s, i + 1, left, right + 1, leftRemove, rightRemove, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            } else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string curr;

        dfs(s, 0, 0, 0, leftRemove, rightRemove, curr);

        return vector<string>(ans.begin(), ans.end());
    }
};