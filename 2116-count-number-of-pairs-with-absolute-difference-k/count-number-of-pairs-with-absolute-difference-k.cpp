class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>omp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(omp.find(nums[i]+k)!=omp.end()){
                cnt+=omp[nums[i]+k];
            }
            if(omp.find(nums[i]-k)!=omp.end()){
                cnt+=omp[nums[i]-k];
            }
            omp[nums[i]]=(omp.find(nums[i])==omp.end())?1:omp[nums[i]]+1;
        }
        return cnt;
    }
};