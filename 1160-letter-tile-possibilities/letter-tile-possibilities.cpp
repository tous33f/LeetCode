class Solution {
public:
    int backtrack(string tiles,string str,vector<bool>&used,unordered_map<string,bool>&ump){
        int cnt=0;
        for(int i=0;i<tiles.size();i++){
            if(ump.find(str+tiles[i])!=ump.end() || used[i]){
                continue;
            }
            ump[str+tiles[i]]=true;
            used[i]=true;
            cnt+=(backtrack(tiles,str+tiles[i],used,ump)+1);
            used[i]=false;
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        string str="";
        vector<bool>used(tiles.size(),0);
        unordered_map<string,bool>ump;
        return backtrack(tiles,str,used,ump);
    }
};