class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        if(s.length()<1) return s;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9' && !st.empty()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            char t=st.top();
            st.pop();
            ans=t+ans;
        }
        return ans;
    }
};