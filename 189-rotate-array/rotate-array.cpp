class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int>arr;
        for(int i=0;i<nums.size()-k;i++){
            arr.push_back(nums[i]);
        }
        for(int i=0,j=nums.size()-k;j<nums.size();j++,i++){
            nums[i]=nums[j];
        }
        for(int i=k,j=0;j<arr.size();j++,i++){
            nums[i]=arr[j];
        }
    }
};