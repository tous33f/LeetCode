class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k-1;i++){
            pq.push({nums[i],i});
        }
        int cur_max=0,j_ans=0,i_ans=k-1;
        vector<int>ans;
        for(int j=0,i=k-1;i<n;i++,j++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<j){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};