class Solution {
public:
    bool DFS(int row,int col,int idx,int n,int m,vector<vector<char>>& board, string word){
        if(idx == word.size()){
            return true;
        }
        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[idx]){
            return false;
        }
        char ch = board[row][col];
        board[row][col] = '#';
        bool found = (
            DFS(row+1,col,idx+1,n,m,board,word) ||
            DFS(row-1,col,idx+1,n,m,board,word) ||
            DFS(row,col+1,idx+1,n,m,board,word) ||
            DFS(row,col-1,idx+1,n,m,board,word) 
        );
        board[row][col] = ch;//backtrack
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(DFS(i,j,0,n,m,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};