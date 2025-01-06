class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int t;
        for(int i=0,j=nums.size()-1;i<(nums.size())/2;i++,j--){
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        for(int i=0,j=k-1;i<k/2;i++,j--){
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        for(int i=k,j=nums.size()-1;i<((nums.size()-k)/2)+k;i++,j--){
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
    }
};