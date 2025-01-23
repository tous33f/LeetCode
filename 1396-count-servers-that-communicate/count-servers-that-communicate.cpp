class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<bool>rows(grid.size(),0);
        vector<bool>cols(grid[0].size(),0);
        //rows
        for(int i=0;i<grid.size();i++){
            bool flag=0;
            for(int j=0;j<grid[0].size();j++){
                if(flag && grid[i][j]){
                    rows[i]=1;
                    break;
                }
                if(grid[i][j]){
                    flag=1;
                }
            }
        }
        //cols
        for(int i=0;i<grid[0].size();i++){
            bool flag=0;
            for(int j=0;j<grid.size();j++){
                if(flag && grid[j][i]){
                    cols[i]=1;
                    break;
                }
                if(grid[j][i]){
                    flag=1;
                }
            }
        }
        //count
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] && (rows[i] || cols[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};