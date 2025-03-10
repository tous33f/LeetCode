class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans=0;
        int n=word.size();
        for(int i=0;i<n-4;i++){
            for(int j=i+4;j<n;j++){
                unordered_map<int,bool>ump={ {'a',0},{'e',0},{'i',0},{'o',0},{'u',0} };
                // string s="";
                int cnt=0;
                for(int k=i;k<=j;k++){
                    // s+=word[k];
                    if(ump.find(word[k])!=ump.end()){
                        if( !ump[word[k]]){
                            cnt++;
                            ump[word[k]]=1;
                        }
                    }
                    else{
                        cnt=0;
                        break;
                    }
                }
                // cout<<s<<"->"<<cnt<<endl;
                if(cnt==5) ans++;
            }
        }
        return ans;
    }
};