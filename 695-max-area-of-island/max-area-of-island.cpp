class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),0));
        vector<vector<int>>arr={ {1,0}, {-1,0}, {0,1}, {0,-1} };
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!grid[i][j]){
                    continue;
                }
                //bfs
                int cur=0;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    pair<int,int>p=q.front();
                    int row=p.first,col=p.second;
                    q.pop();
                    cur+=grid[row][col];
                    for(vector<int>vec:arr){
                        if( row+vec[0]<grid.size() 
                        && row+vec[0]>=0 
                        && col+vec[1]<grid[0].size() 
                        && col+vec[1]>=0 
                        && !vis[row+vec[0]][col+vec[1]] 
                        && grid[row+vec[0]][col+vec[1]] ){
                            q.push( {row+vec[0],col+vec[1]} );
                            vis[row+vec[0]][col+vec[1]]=1;
                        }
                    }
                }
                if(cur>max){
                    max=cur;
                }
            }
        }
        return max;
    }
};