class Solution {
public:
    void backtrack(int n,int k,string str,vector<string>&ans){
        int len=str.length();
        if(ans.size()>=k) return;
        if(len>=n){
            ans.push_back(str);
            return;
        }
        vector<char>con={'a','b','c'};
        for(int i=0;i<3;i++){
            if(str[len-1]==con[i]) continue;
            backtrack(n,k,str+con[i],ans);
        }
    }
    string getHappyString(int n, int k) {
        vector<string>con={"a","b","c"};
        vector<string>ans;
        for(int i=0;i<3;i++){
            backtrack(n,k,con[i],ans);
        }
        return (ans.size()>=k)?ans[k-1]:"";
    }
};