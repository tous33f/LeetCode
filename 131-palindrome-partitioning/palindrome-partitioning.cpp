class Solution {
public:
    bool isPalindrome(string s){
        int n=s.length();
        for(int i=0,j=n-1;i<n && j>=0 && i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    void fun(string s,int cur,vector<string>v,vector<vector<string>>&ans){
        int n=s.length();
        string str="";
        if(cur>=n){
            ans.push_back(v);
            return;
        }
        for(int i=cur;i<n;i++){
            str+=s[i];
            if(!isPalindrome(str)){
                continue;
            }
            v.push_back(str);
            fun(s,i+1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        fun(s,0,v,ans);
        return ans;
    }
};