class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len_i=1,len_d=1,max_i=-1,max_d=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                len_d++;
                if(len_i>max_i){
                    max_i=len_i;
                }
                len_i=1;
            }
            else if(nums[i-1]<nums[i]){
                len_i++;
                if(len_d>max_d){
                    max_d=len_d;
                }
                len_d=1;
            }
            else{
                if(len_i>max_i){
                    max_i=len_i;
                }
                if(len_d>max_d){
                    max_d=len_d;
                }
                len_i=1;
                len_d=1;
            }
        }
        if(len_i>max_i){
            max_i=len_i;
        }
        if(len_d>max_d){
            max_d=len_d;
        }
        // cout<<max_i<<","<<max_d;
        return max_i>max_d?max_i:max_d;
    }
};