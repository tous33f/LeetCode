class Solution {
public:
    bool backtrack(int n,int cur,int t){
        if(cur==n) return true;
        if(cur>n) return false;
        while(t*3<=7174453){
            if(backtrack(n,cur+(t*3),t*3)) return true;
            t*=3;
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        int cur=0,t=1;
        for(int i=1;i<=15;i++){
            if(backtrack(n,cur+t,t)) return true;
            t*=3;
        }
        return false;
    }
};