class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        for(i=0,j=0;i<t.length();i++){
            if(j==s.length()) return true;
            if(s[j]==t[i]) j++;
        }
        return j==s.length()?true:false;
    }
};