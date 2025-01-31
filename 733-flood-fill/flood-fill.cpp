class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size(),key=image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        vector<int>dr={1,0,-1,0};
        vector<int>dc={0,1,0,-1};
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            image[i][j]=color;
            for(int k=0;k<4;k++){
                if( i+dr[k]<m
                && i+dr[k]>=0
                && j+dc[k]<n
                && j+dc[k]>=0
                && image[i+dr[k]][j+dc[k]]==key
                && !vis[i+dr[k]][j+dc[k]] ){
                    q.push({i+dr[k],j+dc[k]});
                    vis[i+dr[k]][j+dc[k]]=1;
                }
            }
        }
        return image;
    }
};