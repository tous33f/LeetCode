class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.size();
        unordered_map<char,int>ump={{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        int cnt=0;
        int ans=0;
        for(int i=0,j=0,k=0;i<n;i++){
            if(ump.find(word[i])!=ump.end()){
                ump[word[i]]++;
                if(ump[word[i]]==1) cnt++;
                for(;cnt==5;k++){
                    ump[word[k]]--;
                    if(ump[word[k]]==0) cnt--;
                }
                ans+=(k-j);
            }
            else{
                j=k=i+1;
                cnt=0;
                ump={{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
            }
        }
        return ans;
    }
};