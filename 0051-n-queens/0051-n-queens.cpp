class Solution {
public:
    bool isSafe(vector<string> &chess,int row,int col,int n){
        // horizontal
        for(int j=0;j<n;j++){
            if(chess[row][j] == 'Q'){
                return false;
            }
        }
        //vertical
        for(int i=0;i<n;i++){
            if(chess[i][col] == 'Q'){
                return false;
            }
        }
        //left Diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void NQueens(vector<string> &chess,int row,int n,vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(chess);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(chess,row,j,n)){
                chess[row][j] = 'Q';
                NQueens(chess,row+1,n,ans);
                chess[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n,string(n,'.'));
        vector<vector<string>> ans;
        NQueens(chess,0,n,ans);
        return ans;
    }
};