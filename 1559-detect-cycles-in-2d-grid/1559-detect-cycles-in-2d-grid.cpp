class Solution {
public:
    bool dfs(int row,int col,int pr,int pc,int n,int m,vector<vector<bool>> &vis,vector<vector<char>>& grid){
        vis[row][col] = true;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == grid[row][col]){
                if(!vis[newRow][newCol]){
                    if(dfs(newRow,newCol,row,col,n,m,vis,grid)){
                        return true;
                    }
                }
                else if(newRow != pr || newCol != pc){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,n,m,vis,grid)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};