class Solution {
    bool backtrack(int n,int cur,vector<bool>&used,vector<int>&ans){
        if(cur==ans.size()) return 1;
        if(ans[cur]>0) return backtrack(n,cur+1,used,ans);
        for(int i=n;i>1;i--){
            if(!used[i] && cur+i<ans.size() && ans[cur+i]==0){
                used[i]=1;
                ans[cur]=i;
                ans[cur+i]=i;
                if(backtrack(n,cur+1,used,ans)) return true;
                used[i]=0;
                ans[cur]=0;
                ans[cur+i]=0;
            }
        }
        if(!used[1]){
            used[1]=1;
            ans[cur]=1;
            if(backtrack(n,cur+1,used,ans)) return true;
            used[1]=0;
            ans[cur]=0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool>used(n+1,0);
        vector<int>ans((n*2)-1,0);
        backtrack(n,0,used,ans);
        return ans;
    }
};

//------------------------UNOPTIMIZED SOLUTION------------------------
// class Solution {
// public:
//     bool fun(int n,int cur,vector<int>&arr,vector<int>&cnt,vector<int>&ans){
//         if(cur==(n*2)-1) return true;
//         for(int i=n;i>0;i--){
//             if(i==1){
//                 if(arr[i]>-1) continue;
//                 else{
//                     arr[i]=cur;
//                     ans[cur]=i;
//                     if(fun(n,cur+1,arr,cnt,ans)) return true;
//                     arr[i]=-1;
//                 }
//             }
//             else if((arr[i]!=-1 && abs(arr[i]-cur)!=i) || cnt[i]==2) continue;
//             else{
//                 ans[cur]=i;
//                 if(cnt[i]<1){
//                     arr[i]=cur;
//                 }
//                 cnt[i]++;
//                 if(fun(n,cur+1,arr,cnt,ans)) return true;
//                 cnt[i]--;
//                 if(cnt[i]<1){
//                     arr[i]=-1;
//                 }
//             }
//         }
//         return false;
//     }
//     vector<int> constructDistancedSequence(int n) {
//         vector<int>arr(n+1,-1);
//         vector<int>cnt(n+1,0);
//         vector<int>ans((n*2)-1,0);
//         fun(n,0,arr,cnt,ans);
//         return ans;
//     }
// };