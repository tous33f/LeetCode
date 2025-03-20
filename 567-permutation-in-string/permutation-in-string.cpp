class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);
        for(auto s:s1){
            freq[int(s-'a')]++;
        }
        int n=s2.length(),m=s1.length();
        // cout<<"s1="<<m<<",s2="<<n<<endl;
        vector<int>check(26,0);
        for(int i=0,j=0;i<n;i++){
            int t=int(s2[i]-'a');
            if( freq[t]<1 ){
                j=i+1;
                for(int k=0;k<26;k++) check[k]=0;
                continue;
            }
            if( (check[t]+1)>freq[t] ){
                for(; s2[j]!=s2[i] ;j++){
                    check[ int(s2[j]-'a') ]--;
                }
                check[ int(s2[j++]-'a') ]--;
            }
            check[t]++;
            if( (i-j+1)==m ) return true;
        }
        return false;
    }
};