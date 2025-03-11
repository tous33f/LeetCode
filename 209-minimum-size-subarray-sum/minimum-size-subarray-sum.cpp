class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        vector<int>ans;
        for(int i=0,j=0;i<n;i++){
            sum+=nums[i];
            while(j<n && sum>=target){
                ans.push_back(i-j+1);
                // cout<<j<<","<<i<<"->"<<sum<<endl;
                sum-=nums[j];
                j++;
            }
        }
        int min=INT_MAX;
        for(int i:ans){
            if(i<min) min=i;
        }
        // cout<<"min="<<min<<endl;
        if(min<INT_MAX) return min;
        else return 0;
    }
};