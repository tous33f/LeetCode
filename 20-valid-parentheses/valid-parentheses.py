class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lo=['(','{','[']
        # lc=[')','}',']']
        # br={'(':')',')':'(','{':'}','}':'{','[':']',']':'['}
        br={')':'(','}':'{',']':'['}
        st=[]
        for ch in s:
            if ch in lo:
                st.append(ch)
            else:
                if len(st)<1 or br[ch]!=st[-1]:
                    return False
                st.pop()
        if len(st)>0:
            return False
        return True