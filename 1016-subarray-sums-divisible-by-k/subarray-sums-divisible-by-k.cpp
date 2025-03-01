class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),mod;
        vector<int>freq(k,0);
        freq[0]=1;
        int sum=0,ans=0;
        for(int num:nums){
            sum+=num;
            mod=((sum%k)+k)%k;
            ans+=freq[mod];
            freq[mod]++;
        }
        return ans;
    }
};