class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b,n=grid.size(),sum=0;
        vector<bool>arr(n*n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[grid[i][j]-1]){
                    a=grid[i][j];
                    continue;
                }
                arr[grid[i][j]-1]=true;
                sum+=grid[i][j];
            }
        }
        float t=(float)(n*n)/2*(2+((n*n)-1));
        return {a,(int)(t-sum)};
    }
};