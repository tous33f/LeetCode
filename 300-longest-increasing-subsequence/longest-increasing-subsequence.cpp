class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max,n=nums.size();
        vector<int>arr(n,1);
        for(int i=1;i<n;i++){
            max=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i] && arr[j]>max) max=arr[j];
            }
            arr[i]=max+1;
        }
        max=0;
        for(int i:arr){
            if(i>max) max=i;
        }
        return max;
    }
};