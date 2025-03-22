class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        ans=[]

        def isValid(s):
            st=[]
            for ch in s:
                if ch=='(':
                    st.append(ch)
                else:
                    if len(st)<1 or st[-1]!='(':
                        return False
                    st.pop()
            if len(st)>0:
                return False
            return True

        def backtrack(s,n):
            if(len(s)>=n):
                if(isValid(s)):
                    ans.append(s)
            else:
                backtrack(s+'(',n)
                backtrack(s+')',n)
        
        backtrack('',n*2)
        return ans