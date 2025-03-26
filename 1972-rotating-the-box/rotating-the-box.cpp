class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size(), m=boxGrid[0].size();

        for(int i=0;i<n;i++){
            // 0-m-1
            int stone = 0, empty = 0;
            while(stone<m && empty<m){
                while(stone<m && boxGrid[i][stone]!='#'){
                    stone++;
                    empty=stone;
                }
                while(empty<m && boxGrid[i][empty]!='.'){
                    if(boxGrid[i][empty]=='*'){//reset the stone
                        stone = empty;
                    }
                    empty++;
                }
                if(stone<m && empty<m && boxGrid[i][stone]=='#' && boxGrid[i][empty]=='.'){
                    //swap
                    swap(boxGrid[i][stone++],boxGrid[i][empty++]);
                }
            }
        }
        vector<vector<char>> ans(m,vector<char> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n-i-1]=boxGrid[i][j];
            }
        }
        return ans;
    }
};