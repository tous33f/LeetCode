class Solution {
public:
    long long coloredCells(int n) {
        // long long corners=0;
        // long long cur=1;
        // for(int i=0;i<n;i++){
        //     cur+=corners;
        //     corners+=4;
        // }
        // return cur;
        return ((( (long long)n * (long long)(n-1) ) *4)/2)+1 ;
    }
};