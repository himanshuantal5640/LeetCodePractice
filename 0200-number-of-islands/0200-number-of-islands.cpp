class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1'){
            return;
        }
        vis[i][j] = true;
        dfs(i-1,j,n,m,vis,grid);
        dfs(i+1,j,n,m,vis,grid);
        dfs(i,j-1,n,m,vis,grid);
        dfs(i,j+1,n,m,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,n,m,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};