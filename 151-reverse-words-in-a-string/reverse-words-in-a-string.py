class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans=""
        while len(s.rstrip())>0:
            s=s.rstrip()
            i=len(s)-1
            while i>0 and s[i-1]!=" ":
                i-=1
            ans+=( s[i:]+" " )
            s=s[:i]
        return ans[:-1]
        