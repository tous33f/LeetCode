class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(!mat[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int dis=1,len;
        while(!q.empty()){
            len=q.size();
            while(len>0){
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i-1>=0 && !visited[i-1][j]){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                    ans[i-1][j]=dis;
                }
                if(i+1<mat.size() && !visited[i+1][j]){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                    ans[i+1][j]=dis;
                }
                if(j-1>=0 && !visited[i][j-1]){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                    ans[i][j-1]=dis;
                }
                if(j+1<mat[0].size() && !visited[i][j+1]){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                    ans[i][j+1]=dis;
                }
                len--;
            }
            dis++;
        }
        return ans;
    }
};