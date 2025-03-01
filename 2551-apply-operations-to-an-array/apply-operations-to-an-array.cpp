class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int t;
        for(int i=0,j=0;i<n && j<n;j++){
            if(nums[j]!=0){
                t=nums[i];
                nums[i]=nums[j];
                nums[j]=t;
                i++;
            }
        }
        return nums;
    }
};