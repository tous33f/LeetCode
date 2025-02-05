class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i=-1,j=-1;
        for(int k=0;k<s1.length();k++){
            if(s1[k]!=s2[k] && i<0){
                i=k;
                continue;
            }
            if(s1[k]!=s2[k] && j<0){
                j=k;
                break;
            }
        
        }
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        string temp;
        char t;
        temp=""+s1;
        t=temp[i];
        temp[i]=temp[j];
        temp[j]=t;
        if(temp==s2) return true;
        temp=""+s2;
        t=temp[i];
        temp[i]=temp[j];
        temp[j]=t;
        if(temp==s1) return true;
        return false;
    }
};