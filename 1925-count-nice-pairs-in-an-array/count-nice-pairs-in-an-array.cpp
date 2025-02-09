class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long long,long long>omp;
        long long cnt=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int rev=0;
            while(num>0){
                rev*=10;
                rev+=num%10;
                num/=10;
            }
            if(omp.find(nums[i]-rev)==omp.end()){
                omp[nums[i]-rev]=1;
            }
            else{
                cnt+=omp[nums[i]-rev];
                omp[nums[i]-rev]++;
            }
        }
        return int( cnt%1000000007 );
    }
};