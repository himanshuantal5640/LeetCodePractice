class Solution {
public:
    void DFS(int i,int j,int n,int m,vector<vector<int>>& heights,vector<vector<bool>>& vis){
        vis[i][j] = true;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && heights[ni][nj] >= heights[i][j]){
                DFS(ni,nj,n,m,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        // for row
        for(int i = 0;i <n ;i++){
            DFS(i,0,n,m,heights,pacific);//pacific left boundary
            DFS(i,m-1,n,m,heights,atlantic);//atlantic right boundary
        }
        // for column
        for(int j=0;j<m;j++){
            DFS(0,j,n,m,heights,pacific);//pacific top boundary
            DFS(n-1,j,n,m,heights,atlantic);//atlantic bottom boundary
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};