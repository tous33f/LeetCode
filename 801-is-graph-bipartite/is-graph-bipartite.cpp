class Solution {
public:
    int find(vector<int>&arr,int x){
        while(arr[x]!=x){
            x=arr[x];
        }
        return x;
    }
    void join(vector<int>&arr,int x,int y){
        int p_x=find(arr,x),p_y=find(arr,y);
        if(p_x==p_y){
            return;
        }
        arr[p_x]=p_y;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>parent;
        for(int i=0;i<graph.size();i++) parent.push_back(i);
        vector<bool>vis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(vis[i]){
                continue;
            }
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                int prev=(graph[v].size()>0?graph[v][0]:-1);
                for(int j:graph[v]){
                    if(find(parent,v)==find(parent,j)){
                        return false;
                    }
                    join(parent,prev,j);
                    if(!vis[j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};