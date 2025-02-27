class Solution {
public:
    int fib(int n) {
        if(n==0) return n;
        int first=0,second=1;
        int res;
        for(int i=1;i<=n-1;i++){
            res=first+second;
            first=second;
            second=res;
        }
        return second;
    }
};