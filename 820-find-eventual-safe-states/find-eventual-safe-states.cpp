class Solution {
public:
    void top(int v, vector<vector<int>>& graph, vector<int>& visited, stack<int>& st){
        visited[v]=1;
        for(int i:graph[v]){
            if(!visited[i]){
                top(i,graph,visited,st);
            }
        }
        st.push(v);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        stack<int>st;
        vector<int>visited(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                top(i,graph,visited,st);
            }
        }
        vector<bool>check(graph.size(),0);
        vector<int>sorted;
        while(!st.empty()){
            sorted.push_back(st.top());
            st.pop();
        }
        for(int i=sorted.size()-1;i>=0;i--){
            bool flag=1;
            for(int j=0;j<graph[sorted[i]].size();j++){
                int t=graph[sorted[i]][j];
                if(!check[t]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                check[sorted[i]]=1;
            }
        }
        vector<int>ans;
        for(int i=0;i<check.size();i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};