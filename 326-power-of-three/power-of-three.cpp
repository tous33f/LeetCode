class Solution {
public:
    bool isPowerOfThree(int n) {
        long long t=1;
        while(t<n){
            t*=3;
        }
        if(t==n) return true;
        return false;
    }
};