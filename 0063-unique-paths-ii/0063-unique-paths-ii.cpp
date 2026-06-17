class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i < n && j < m && mat[i][j] == 1){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = solve(i+1,j,n,m,mat,dp);
        int down = solve(i,j+1,n,m,mat,dp);
        return dp[i][j] = up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,obstacleGrid,dp);
    }
};