class Solution {
public:
    bool fun(vector<int>& gas, vector<int>& cost,int cur){
        int n=gas.size();
        int fuel,amount=cost[cur],tank=gas[cur];
        int i=(cur+1)%n;
        while(i!=cur){
            tank-=amount;
            if(tank<0) return false;
            tank+=gas[i];
            amount=cost[i];
            i=(i+1)%n;
        }
        if(tank-amount<0) return false;
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int j=0;
        int total_gas=0,total_cost=0;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            if(gas[i]-cost[i]<0) continue;
            pq.push({gas[i]-cost[i],i});
        }
        if(total_gas<total_cost) return -1;
        while(!pq.empty()){
            if(fun(gas,cost,pq.top().second)) return pq.top().second;
            pq.pop();
        }
        return -1;
    }
};