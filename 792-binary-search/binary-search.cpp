class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mid=0,left=0,right=n-1;
        while(left<=right){
            mid=int((left+right)/2);
            // cout<<mid<<endl;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(nums[mid]==target) return mid;
        return -1;
    }
};