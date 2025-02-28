class Solution {
public:
    vector<vector<int>> build_graph(vector<vector<int>>& edges){
        vector<vector<int>>graph;
        graph.resize(edges.size()+1);
        for(vector vec:edges){
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        return graph;
    }
    bool traverse_bob(vector<vector<int>>&graph,int n,int cur,int time,vector<bool>&visited,
    unordered_map<int,int>&ump){
        // cout<<cur<<" ";
        if(cur==0){
            ump[cur]=time;
            return true;
        }
        for(int i:graph[cur]){
            if(!visited[i]){
                visited[i]=1;
                if(traverse_bob(graph,n,i,time+1,visited,ump)){
                    ump[cur]=time;
                    return true;
                }
                ump.erase(cur);
                visited[i]=0;
            }
        }
        return false;
    }
    int traverse_alice(vector<vector<int>>&graph,int n,int cur,int time,vector<bool>&visited,unordered_map<int,int>&ump,vector<int>&amount){
        visited[cur]=1;
        int cost=0;
        if(ump.find(cur)!=ump.end() && time==ump[cur]){
            cost=int(amount[cur]/2);
        }
        else if(ump.find(cur)!=ump.end() && time>ump[cur]);
        else{
            cost=amount[cur];
        }
        int max=INT_MIN,t;
        for(int i:graph[cur]){
            if(!visited[i]){
                t=traverse_alice(graph,n,i,time+1,visited,ump,amount);
                if(t>max) max=t;
            }
        }
        if(max==INT_MIN) max=0;
        // cout<<cur<<"->"<<cost<<","<<max<<":"<<cost+max<<endl;
        return cost+max;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>graph=build_graph(edges);
        unordered_map<int,int>ump;
        vector<bool>visited(n,0);
        visited[bob]=1;
        traverse_bob(graph,n,bob,1,visited,ump);
        // for(auto i:ump) cout<<i.first<<","<<i.second<<endl;
        for(int i=0;i<n;i++)visited[i]=0;
        return traverse_alice(graph,n,0,1,visited,ump,amount);
    }
};