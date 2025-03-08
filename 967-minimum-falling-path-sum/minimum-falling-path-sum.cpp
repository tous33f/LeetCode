class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>arr;
        for(int i=0;i<n;i++) arr.push_back(matrix[0][i]);
        for(int i=1;i<n;i++){
            vector<int>t;
            for(int j=0;j<n;j++){
                int min=INT_MAX;
                if(j-1>=0 && matrix[i][j]+arr[j-1]<min) min=matrix[i][j]+arr[j-1];
                if(matrix[i][j]+arr[j]<min) min=matrix[i][j]+arr[j];
                if(j+1<n && matrix[i][j]+arr[j+1]<min) min=matrix[i][j]+arr[j+1];
                t.push_back(min);
            }
            for(int l=0;l<n;l++) arr[l]=t[l];
        }
        int ans=INT_MAX;
        for(int i:arr){
            if(i<ans) ans=i;
        }
        return ans;
    }
};