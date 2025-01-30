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
    int bfs(int n,vector<vector<int>>&graph,vector<int>vertices){
        int max=0;
        for(int v:vertices){
            int cnt=0;
            queue<int>q;
            vector<bool>vis(n,0);
            q.push(v);
            vis[v]=1;
            while(!q.empty()){
                cnt++;
                int size=q.size();
                for(int i=0;i<size;i++){
                    int p=q.front();
                    q.pop();
                    for(int j:graph[p]){
                        if(!vis[j]){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
            if(cnt>max){
                max=cnt;
            }
        }
        return max;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph;
        for(int i=0;i<n;i++){
            graph.push_back({});
        }
        for(vector<int>v:edges){
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        //check bipartite
        if(!isBipartite(graph)){
            return -1;
        }
        //form connected components
        vector<int>dsu;
        for(int i=0;i<n;i++) dsu.push_back(i);
        for(vector<int>v:edges) join(dsu,v[0]-1,v[1]-1);
        map<int,vector<int>>mp;
        for(int i=0;i<dsu.size();i++){
            cout << find(dsu,i) << ":"<<i<<endl;
            mp[find(dsu,i)].push_back(i);
        }
        int ans=0;
        map<int, vector<int>>::iterator it = mp.begin();
        while (it != mp.end()) {
            ans+=bfs(n,graph,it->second);
            it++;
        }
        return ans;
    }
};