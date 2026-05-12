class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        int nx[] = {-1,1,0,0};//up down left right
        int my[] = {0,0,-1,1};//up down left right
        for(int k = 0;k<4;k++){
            int ni = i + nx[k];
            int mj = j + my[k];
            if(ni >= 0 && mj >= 0 && ni < n && mj < m && matrix[ni][mj] > matrix[i][j]){
                ans = max(ans,1+dfs(ni,mj,matrix,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int maxi = 1;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,dfs(i,j,matrix,dp));
            }
        }
        return maxi;
    }
};