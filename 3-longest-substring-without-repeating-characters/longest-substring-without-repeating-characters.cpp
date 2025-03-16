class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,n=s.length(),ans=0;
        unordered_map<char,int>ump={};
        for(i=0,j=0;i<n && j<n;i++){
            if(ump.find(s[i])!=ump.end()){
                ans=max(ans,i-j);
                int wall=ump[s[i]];
                for(;j<=wall;j++){
                    ump.erase(s[j]);
                }
            }
            ump[s[i]]=i;
        }
        return max(ans,i-j);
    }
};