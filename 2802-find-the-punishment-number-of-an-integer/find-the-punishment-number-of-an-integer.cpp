class Solution {
public:
    bool fun(vector<int>nums,int cur,int sum,int number){
        int n=nums.size();
        if(cur>=n){
            if(sum==number) return true;
            else return false;
        }
        int cnt=0;
        for(int i=cur;i<n;i++){
            cnt*=10;
            cnt+=nums[i];
            if(fun(nums,i+1,sum+cnt,number)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            vector<int>temp;
            int num=i*i;
            while(num>0){
                temp.push_back(num%10);
                num/=10;
            }
            vector<int>nums;
            for(int i=temp.size()-1;i>=0;i--) nums.push_back(temp[i]);
            if(fun(nums,0,0,i)) ans+=(i*i);
        }
        return ans;
    }
};