class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row,col,rows=matrix.size(),cols=matrix[0].size();
        int mid,left=0,right=(rows*cols)-1;
        while(left<=right){
            mid=(left+right)/2;
            row=mid/cols;
            col=mid%cols;
            // cout<<"left="<<left<<",right"<<right<<endl;
            // cout<<matrix[row][col]<<","<<mid<<endl<<endl;
            if(matrix[row][col]==target) return 1;
            else if(matrix[row][col]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return 0;
    }
};