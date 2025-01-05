class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val=101;
        for(int i=1,j=0;i<nums.size() && j<nums.size();i++){
            if(nums[i]==nums[j]){
                nums[i]=val;
            }
            else{
                j=i;
            }
        }
        int pi=0,pj=0;
        for(pi=0;pi<nums.size();pi++){
            if(nums[pi]==val){
                continue;
            }
            else{
                int t=nums[pi];
                nums[pi]=nums[pj];
                nums[pj++]=t;
            }
        }
        return pj;
    }
};