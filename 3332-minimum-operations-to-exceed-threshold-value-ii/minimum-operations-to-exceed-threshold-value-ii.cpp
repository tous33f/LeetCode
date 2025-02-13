class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long, vector<long>, greater<long> > pq;
        unordered_map<int,bool>ump;
        int freq=0;
        for(int num:nums){
            if(num<k) freq++;
            pq.push(long(num));
        }
        int cnt=0;
        while(pq.size()>1 && freq>0){
            long first=pq.top();
            pq.pop();
            long second=pq.top();
            pq.pop();
            long t=(min(first,second)*2)+max(first,second);
            if(t<k) freq--;
            else freq-=2;
            pq.push(t);
            cnt++;
        }
        return cnt;
    }
};