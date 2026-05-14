class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1){
            return 0;
        }
        vis[i][j] = true;
        int ans = 1;
        ans += dfs(i-1,j,n,m,vis,grid);
        ans += dfs(i+1,j,n,m,vis,grid);
        ans += dfs(i,j-1,n,m,vis,grid);
        ans += dfs(i,j+1,n,m,vis,grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    maxi = max(maxi,dfs(i,j,n,m,vis,grid));
                }
            }
        }
        return maxi;
    }
};