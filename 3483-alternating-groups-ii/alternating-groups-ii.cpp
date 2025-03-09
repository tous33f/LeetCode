class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        /*-------------------- OPTIMIZED SOL --------------------*/
        // for(int i=0;i<k-1;i++) colors.push_back(colors[i]);
        int n=colors.size(),size=n+k-1,cur=1;
        int cnt=0,win=1;
        while(cur<size){
            if(colors[cur%n]!=colors[((cur-1)+n)%n]){
                win++;
            }
            else{
                int t=win-k+1;
                cnt+=(t>0?t:0);
                win=1;
            }
            cur++;
        }
        int t=win-k+1;
        cnt+=(t>0?t:0);
        return cnt;

        /*-------------------- UNOPTIMIZED SOL --------------------*/
        // int cnt=0;
        // int n=colors.size();
        // int cur=0;
        // cout<<n<<endl;
        // do{
        //     bool flag=1;
        //     for(int i=(cur+1)%n,j=0;j<k-1;i=(i+1)%n,j++){
        //         // cout<<((i-1)+n)%n<<","<<i<<" ";
        //         if(colors[i]==colors[((i-1)+n)%n]){
        //             if(((i-1)+n)%n>=cur) cur=((i-1)+n)%n;
        //             else cur=n-1;
        //             flag=0;
        //             break;
        //         }
        //     }
        //     // cout<<endl;
        //     if(flag) cnt++;
        //     cur=(cur+1)%n;
        //     cout<<cur<<endl;
        // }while(cur!=0);
        // return cnt;
    }
};