class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> ump;
        int max=-1;
        for(int i=0;i<nums.size();i++){
            int t=nums[i],num=0;
            while(t>0){
                num+=t%10;
                t/=10;
            }
            if(ump.find(num)!=ump.end()){
                max=(max<(nums[i]+ump[num]))?(nums[i]+ump[num]):max;
                ump[num]=(ump[num]<nums[i])?nums[i]:ump[num];
            }
            else{
                ump[num]=nums[i];
            }
        }
        return max;
    }
};