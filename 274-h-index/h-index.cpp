class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>h_arr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(citations[j]>=i+1) h_arr[i]++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(h_arr[i]>=i+1) return i+1;
        }
        return 0;
    }
};