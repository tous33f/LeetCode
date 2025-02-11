class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(st.top()!=part[part.length()-1]){
                continue;
            }
            stack<char>stt;
            bool flag=1;
            for(int j=part.length()-1;j>=0;j--){
                if(st.empty() || part[j]!=st.top()){
                    flag=0;
                    break;
                }
                else{
                    stt.push(st.top());
                    st.pop();
                }
            }
            if(!flag){
                while(!stt.empty()){
                    st.push(stt.top());
                    stt.pop();
                }
            }
        }
        while(!st.empty()){
            char t=st.top();
            st.pop();
            ans=t+ans;
        }
        return ans;
    }
};