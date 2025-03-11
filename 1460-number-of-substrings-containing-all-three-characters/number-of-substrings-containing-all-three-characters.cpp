class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0,ans=0;
        unordered_map<char,int>ump={{'a',0},{'b',0},{'c',0}};
        for(int i=0,j=0,k=0;i<n;i++){
            if(ump.find(s[i])!=ump.end()){
                ump[s[i]]++;
                if(ump[s[i]]==1) cnt++;
                for(;cnt==3;j++){
                    ump[s[j]]--;
                    if(ump[s[j]]==0) cnt--;
                }
                ans+=(j-k);
            }
            else{
                cnt=0;
                j=k=i+1;
                ump={{'a',0},{'b',0},{'c',0}};
            }
        }
        return ans;
    }
};