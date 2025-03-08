class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int min=INT_MAX;
        for(int i=0;i+k-1<n;i++){
            int cnt=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j]=='W') cnt++;
            }
            if(cnt<min) min=cnt;
        }
        return min;
    }
};