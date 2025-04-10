class Solution {
    private:
    bool isValid(int newx, int newy, int n, int m){
        return (newx >= 0 && newx < n && newy >= 0 && newy < m);
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // 0,0 -> n-1,m-1   remove k obsticles
        // find min steps
        
        int n = grid.size(), m=grid[0].size();
        // {k, {x,y}}
        queue<pair<int,pair<int,int>>> bfsq;
        int steps=0;
        bfsq.push({k,{0,0}});
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>> (m, vector<bool> (k+1,false)));
        visited[0][0][k]=true;

        while(!bfsq.empty()){
            int size = bfsq.size();
            
            while(size--){
                auto qtop = bfsq.front(); 
                bfsq.pop();
                int currK = qtop.first, x = qtop.second.first, y = qtop.second.second;

                if(x==n-1 && y==m-1){
                    return steps;
                }

                int delrow[] = {0,0,-1,1};
                int delcol[] = {-1,1,0,0};
                
                for(int l = 0;l<4;l++){
                    int newx = x + delrow[l], newy = y + delcol[l];
                    if(isValid(newx,newy,n,m)){
                        if(grid[newx][newy]==0 && !visited[newx][newy][currK]){
                            bfsq.push({currK,{newx,newy}});
                            visited[newx][newy][currK]=true;
                        }else if(grid[newx][newy]==1 && currK>0 && !visited[newx][newy][currK-1]){
                            bfsq.push({currK-1,{newx,newy}});
                            visited[newx][newy][currK-1]=true;
                        }
                    }
                }
            }steps++;
            
        }
        return -1;

    }
};