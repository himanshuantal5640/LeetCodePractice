class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0;row<9;row++){
            for(int col = 0;col<9;col++){
                if(board[row][col] == '.'){
                    continue;
                }
                char dig = board[row][col];
                //check col
                for(int j=0;j<9;j++){
                    if(j != col && board[row][j] == dig){
                        return false;
                    }
                }
                //check row
                for(int i=0;i<9;i++){
                    if(i != row && board[i][col] == dig){
                        return false;
                    }
                }
                //check 3X3 grid
                int sr = (row/3)*3;
                int sc = (col/3)*3;
                for(int i=sr;i<sr+3;i++){
                    for(int j=sc;j<sc+3;j++){
                        if((i != row || j != col) && board[i][j] == dig){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};