class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()<1) return true;
        int start=0,n=nums.size();
        bool flag=1;
        vector<int>sorted;
        sorted.push_back(nums[0]);
        for(int i=1;i<n;i++){
            sorted.push_back(nums[i]);
            if(nums[i-1]>nums[i] && flag){
                start=i;
                flag=0;
            }
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            if(nums[(start+i)%n]!=sorted[i]){
                return false;
            }
        }
        return true;
    }
};