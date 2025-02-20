class Solution {
public:
    string backtrack(int n,string cur,unordered_map<string,bool>&ump){
        if(cur.length()>=n){
            if(ump.find(cur)==ump.end()) return cur;
            else return "";
        }
        string str;
        vector<char>arr={'0','1'};
        for(char i:arr){
            str=backtrack(n,cur+i,ump);
            if(str.length()>0) return str;
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,bool>ump;
        for(string i:nums){
            ump[i]=true;
        }
        return backtrack(nums.size(),"",ump);
    }
};