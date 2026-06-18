class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i == n-1){
            return mat[i][j];
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        int down = mat[i][j] + solve(i+1,j,n,mat,dp);
        int dia = mat[i][j] + solve(i+1,j+1,n,mat,dp);
        return dp[i][j] = min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return solve(0,0,n,triangle,dp);
    }
};