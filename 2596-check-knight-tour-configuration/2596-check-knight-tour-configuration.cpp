class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int r,int c,int n,int val){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != val){
            return false;
        }
        if(val == n*n -1){
            return true;
        }
        //8 possible move
        bool a1 = isValid(grid,r-2,c+1,n,val+1);
        bool a2 = isValid(grid,r-1,c+2,n,val+1);
        bool a3 = isValid(grid,r+1,c+2,n,val+1);
        bool a4 = isValid(grid,r+2,c+1,n,val+1);
        bool a5 = isValid(grid,r+2,c-1,n,val+1);
        bool a6 = isValid(grid,r+1,c-2,n,val+1);
        bool a7 = isValid(grid,r-1,c-2,n,val+1);
        bool a8 = isValid(grid,r-2,c-1,n,val+1);
        return a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return isValid(grid,0,0,n,0);
    }
};