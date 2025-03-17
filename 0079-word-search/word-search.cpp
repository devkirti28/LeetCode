class Solution {
private:
    int drow[4] = {0,0,-1,1};
    int dcol[4] = {-1,1,0,0};
    bool isValid(int i, int j, int n, int m){
        return !(i<0 || i>=n || j<0 || j>=m);
    }
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j){
        if(index+1 == word.size())return true;

        char temp = board[i][j];
        board[i][j]='#';
        bool result=false;
        for(int k=0;k<4;k++){
            int newi = i + drow[k], newj = j + dcol[k];
            if(isValid(newi,newj, board.size(), board[0].size()) && board[newi][newj]!='#' && board[newi][newj]==word[index+1]){
                result = result || dfs(board,word, index+1, newi, newj);
            }
        }
        board[i][j]=temp;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, 0, i, j))return true;
                }
            }
        }
        return false;
    }
};