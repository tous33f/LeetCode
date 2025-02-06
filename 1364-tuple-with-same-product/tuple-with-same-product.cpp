class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ump.find(nums[i]*nums[j])==ump.end()){
                    ump[nums[i]*nums[j]]=1;
                }
                else{
                    ump[nums[i]*nums[j]]=ump[nums[i]*nums[j]]+1;
                }
            }
        }
        int cnt=0;
        unordered_map<int,int>::iterator itr;
        for(itr=ump.begin();itr!=ump.end();itr++){
            if(itr->second<2){
                continue;
            }
            int t=itr->second;
            cnt+=( t*(t-1) )*4;
        }
        return cnt;
    }
};