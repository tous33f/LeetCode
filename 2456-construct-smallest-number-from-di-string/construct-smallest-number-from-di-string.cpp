class Solution {
public:
    bool backtrack(string pattern,vector<bool>&used,vector<int>&ans,int cur){
        int n=pattern.size();
        if(cur==n+1){
            return true;
        }
        for(int i=1;i<=n+1;i++){
            if(used[i]) continue;
            if(pattern[cur-1]=='I' && i>ans[cur-1]){
                used[i]=1;
                ans[cur]=i;
                if(backtrack(pattern,used,ans,cur+1)) return true;
                used[i]=0;
                ans[cur]=0;
            }
            else if(pattern[cur-1]=='D' && i<ans[cur-1]){
                used[i]=1;
                ans[cur]=i;
                if(backtrack(pattern,used,ans,cur+1)) return true;
                used[i]=0;
                ans[cur]=0;
            }
            else{
                break;
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        int n=pattern.size();
        vector<bool>used(n+1,0);
        vector<int>ans(n+1,0);
        for(int i=1;i<=n+1;i++){
            ans[0]=i;
            used[i]=1;
            if(backtrack(pattern,used,ans,1)) break;
            ans[0]=0;
            used[i]=0;
        }
        string str="";
        for(int i:ans){
            str+=char('0'+i);
        }
        return str;
    }
};