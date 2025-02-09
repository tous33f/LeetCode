class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt=0;
        long long n=nums.size();
        unordered_map<long long,long long>omp;
        for(long long i=0;i<n;i++){
            if(omp.find(nums[i]-i)==omp.end()){
                omp[nums[i]-i]=1;
            }
            else{
                cnt+=omp[nums[i]-i];
                omp[nums[i]-i]++;
            }
        }
        return ((n*(n-1))/2)-cnt;
    }
};