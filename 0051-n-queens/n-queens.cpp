class Solution {
private:
    vector<vector<string>> ans;
    bool isValid(int x, int y, vector<string>& board){
        //check col
        for(int i=0;i<x;i++){
            if(board[i][y]=='Q'){
                return false;
            }
        }
        int i=x-1,j=y-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j--;
        }
        i=x-1,j=y+1;
        while(i>=0 && j<board.size()){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j++;
        }
        return true;
    }
    bool dfs(int i, int count, vector<string>& board){
        int n = board.size();
        if(count==n){
            ans.push_back(board);
            return true;
        }
        if(i==n)return false;

        //place q in a row

        for(int j=0;j<n;j++){
            // place at i,j
            if(isValid(i,j,board)){
                board[i][j]='Q';
                dfs(i+1,count+1,board);
                board[i][j]='.';
            }
        }
        return false;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string row(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++){
            board.push_back(row);
        }
        dfs(0,0,board);
        return ans;
    }
};