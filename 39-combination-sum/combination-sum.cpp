class Solution {
public:
    void backtrack(vector<int>&nums,int target,int cur_i,int cur_sum,vector<int>v,
    vector<vector<int>>&ans){
        for(int i=cur_i;i<nums.size();i++){
            if(cur_sum+nums[i]>target){
                break;
            }
            if(cur_sum+nums[i]==target){
                v.push_back(nums[i]);
                ans.push_back(v);
                v.pop_back();
            }
            else{
                v.push_back(nums[i]);
                backtrack(nums,target,i,cur_sum+nums[i],v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0,v,ans);
        return ans;
    }
};