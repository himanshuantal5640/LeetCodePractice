class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: Validate diagonal
        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n - i) return "";
        }
        
        string word(n, '?');
        char ch = 'a';
        
        // Step 2: Assign characters
        for(int i = 0; i < n; i++) {
            if(word[i] == '?') {
                if(ch > 'z') return ""; // only 26 chars
                
                for(int j = i; j < n; j++) {
                    if(lcp[i][j] > 0) {
                        word[j] = ch;
                    }
                }
                ch++;
            }
        }
        
        // Step 3: Validate LCP
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(word[i] == word[j]) {
                    dp[i][j] = 1;
                    if(i + 1 < n && j + 1 < n) {
                        dp[i][j] += dp[i + 1][j + 1];
                    }
                }
            }
        }
        
        // Compare with given lcp
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }
        
        return word;
    }
};