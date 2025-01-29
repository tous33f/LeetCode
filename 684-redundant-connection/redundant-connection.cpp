class Solution {
public:
    int find(vector<int> &arr,int x){
        while(arr[x]>=0){
            x=arr[x];
        }
        return x;
    }
    void add(vector<int> &arr,int x,int y){
        int p_x=find(arr,x),p_y=find(arr,y);
        arr[p_x]=p_y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>parent(edges.size(),-1);
        for(vector<int>v:edges){
            int x=v[0]-1,y=v[1]-1;
            if( find(parent,x)==find(parent,y) ){
                ans=v;
                break;
            }
            else{
                add(parent,x,y);
            }
        }
        return ans;
    }
};