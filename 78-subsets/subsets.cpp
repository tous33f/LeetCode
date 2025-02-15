class Solution {
public:
    void fun(vector<int>& nums,int cur,vector<int>&v,vector<vector<int>>&ans){
        if(cur>=nums.size()) return;
        for(int i=cur;i<nums.size();i++){
            v.push_back(nums[i]);
            ans.push_back(v);
            fun(nums,i+1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans={{}};
        vector<int>v;
        fun(nums,0,v,ans);
        return ans;
    }
};