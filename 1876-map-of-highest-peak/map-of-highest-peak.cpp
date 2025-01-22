class Solution {
public:
    // traverse and change 0 to 1 and 1 to 0
    // while traversing, enqueue those indexes to queue which are changed from 0 to 1
    // preform BFS after traversal
    // find min from adjacent nodes and set the current count as min+1
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<int>q_i;
        queue<int>q_j;
        vector<vector<int>>visited(isWater.size(),vector<int>(isWater[0].size(),0));
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==0){
                    isWater[i][j]=1;
                }
                else{
                    q_i.push(i);
                    q_j.push(j);
                    isWater[i][j]=0;
                    visited[i][j]=1;
                }
            }
        }
        int i,j,len,height=1;
        while(!q_i.empty() && !q_i.empty()){
            len=q_i.size();
            while(len>0){
            i=q_i.front();
            q_i.pop();
            j=q_j.front();
            q_j.pop();
            //top
            if(i-1>=0 && !visited[i-1][j]){
                q_i.push(i-1);
                q_j.push(j);
                visited[i-1][j]=1;
                isWater[i-1][j]=height;
            }
            //botton
            if(i+1<isWater.size() && !visited[i+1][j]){
                q_i.push(i+1);
                q_j.push(j);
                visited[i+1][j]=1;
                isWater[i+1][j]=height;
            }
            //left
            if(j-1>=0 && !visited[i][j-1]){
                q_i.push(i);
                q_j.push(j-1);
                visited[i][j-1]=1;
                isWater[i][j-1]=height;
            }
            //right
            if(j+1<isWater[0].size() && !visited[i][j+1]){
                q_i.push(i);
                q_j.push(j+1);
                visited[i][j+1]=1;
                isWater[i][j+1]=height;
            }
            len--;
            }
            height++;
        }
        return isWater;
    }
};