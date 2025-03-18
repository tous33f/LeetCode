class Solution {
public:
    int get_max(vector<int>nums){
        int max=0;
        for(auto num:nums){
            if(num>max){
                max=num;
            }
        }
        return max;
    }
    int characterReplacement(string s, int k) {
        // loop i for end itr and j for start itr
        // update cnt of current char and get max cnt from it
        // check if k >= max-(len sub str)
        // if condition is true then i++
        // else cnt-- the jth char and j++
        vector<int>arr(26,0);
        int n=s.length();
        int ans=0;
        for(int i=0,j=0;i<n;i++){
            arr[int(s[i]-'A')]++;
            // cout<<i<<","<<j<<endl;
            for(; k<( i-j+1-get_max(arr) );j++ ){
                arr[int(s[j]-'A')]--;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};