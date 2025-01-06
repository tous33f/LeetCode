class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1;
        int j=0;
        int cur=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j] || i==nums.size()-1){
                if(i==nums.size()-1) cnt++;
                if(cnt>nums.size()/2){
                    cur=nums[j];
                    break;
                }
                cnt=1;
                j=i;
            }
            else{
                cnt++;
            }
        }
        return cur;
    }
};