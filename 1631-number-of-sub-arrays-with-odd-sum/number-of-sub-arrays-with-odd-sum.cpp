class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0,sum=0,mod;
        int n=arr.size();
        vector<long long>freq(2,0);
        freq[0]=1;
        for(int num:arr){
            sum+=num;
            mod=((sum%2)+2)%2==0?1:0;
            ans+=freq[mod];
            freq[mod==0?1:0]++;
        }
        return ans%(1000000000+7);
    }
};