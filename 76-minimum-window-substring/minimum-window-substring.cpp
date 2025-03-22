class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(),n=t.length();
        if(n>m) return "";
        int tot_len=n;
        vector<int>tot_freq(58,0);
        for(auto chr:t){
            tot_freq[int(chr-'A')]++;
        }
        int cur_len=0,i_ans=m-1,j_ans=0;
        vector<int>cur_freq(58,0);
        for(int i=0,j=0;i<m;i++){


            // cout<<i<<","<<j<<endl;


            int i_idx=int(s[i]-'A');
            int j_idx=int(s[j]-'A');


            if( tot_freq[j_idx]<1  ){
                j++;
                for(int k=0;k<58;k++) cur_freq[k]=0;
                continue;
            }


            if( tot_freq[i_idx]<1 ) continue;


            cur_freq[i_idx]++;


            if(cur_freq[i_idx]<=tot_freq[i_idx]) cur_len++;


            for( ; j<i && ( cur_freq[int(s[j]-'A')]<1 || 
            ( cur_freq[int(s[j]-'A')]>0 && 
            cur_freq[int(s[j]-'A')]-1>=tot_freq[int(s[j]-'A')] ) ) ; j++ ){
                if(cur_freq[int(s[j]-'A')]>0) cur_freq[int(s[j]-'A')]--;
            }


            if(cur_len==tot_len && (i_ans-j_ans+1)>(i-j+1) ){
                i_ans=i;
                j_ans=j;
                // cout<<i_ans<<"-"<<j_ans<<endl;
            }

            // cout<<i<<","<<j<<"->"<<cur_len<<endl;

        }
        if(cur_len<tot_len) return "";
        string ans="";
        for(int k=j_ans;k<=i_ans;k++){
            ans+=s[k];
        }
        return ans;
    }
};