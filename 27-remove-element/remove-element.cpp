class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
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