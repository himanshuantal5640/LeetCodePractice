class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        //horizontal
        for(int j=0;j<9;j++){
            if(board[row][j] == dig){
                return false;
            }
        }
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        //grid
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool SS(vector<vector<char>>& board,int row,int col){
        if(row == 9){
            return true;
        }
        int nextRow = row;
        int nextCol = col+1;
        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return SS(board,nextRow,nextCol);
        }
        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col] = i;
                if(SS(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        SS(board,0,0);
    }
};