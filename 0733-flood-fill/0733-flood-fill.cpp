class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int n,int m,int newColor,int orgColor){
        if(i<0 ||j<0 ||i>=n ||j>=m || image[i][j] != orgColor ||image[i][j] == newColor){
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,n,m,newColor,orgColor);//top
        dfs(image,i,j+1,n,m,newColor,orgColor);//right
        dfs(image,i+1,j,n,m,newColor,orgColor);//bottom
        dfs(image,i,j-1,n,m,newColor,orgColor);//left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        dfs(image,sr,sc,n,m,color,image[sr][sc]);
        return image;
    }
};