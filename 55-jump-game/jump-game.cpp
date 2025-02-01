class Solution {
public:
    bool fun(vector<int>&nums,vector<int>&dp,int i){
        if(i==nums.size()-1){
            dp[i]=1;
            return true;
        }
        if(i>=nums.size()){
            dp[i]=0;
            return false;
        }
        if(dp[i]>-1){
            return dp[i];
        }
        for(int j=i+1;j<=i+nums[i];j++){
            if(fun(nums,dp,j)){
                dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(fun(nums,dp,0)){
            return true;
        }
        return false;
    }
};