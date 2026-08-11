class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=0;k<m;k++){
            int cost = moveCost[grid[i][j]][k] + solve(i+1,k,grid,moveCost,dp);
            ans = min(ans,cost);
        }
        return dp[i][j] = grid[i][j] + ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MAX;
        for(int j = 0;j<m;j++){
            ans = min(ans,solve(0,j,grid,moveCost,dp));
        }
        return ans;
    }
};