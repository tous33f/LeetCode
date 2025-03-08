class Solution {
public:
    string convert(string s, int numRows) {
        int cur=0,n=numRows,l=s.length();
        vector<vector<int>>arr;
        for(int i=0;i<n;i++) arr.push_back(vector<int>{});
        while(cur<l){
            for(int i=0;i<n && cur<l;i++){
                arr[i].push_back(s[cur]);
                cur++;
            }
            for(int i=n-2;i>0 && cur<l;i--){
                for(int j=0;j<n && cur<l;j++){
                    if(j==i){
                        arr[j].push_back(s[cur]);
                        cur++;
                    }
                    else{
                        arr[j].push_back('0');
                    }
                }
            }
        }
        string ans="";
        for(auto i:arr){
            for(auto j:i){
                if(j!='0') ans+=j;
            }
        }
        return ans;
    }
};