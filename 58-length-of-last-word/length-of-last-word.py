class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        i=len(s)-1
        while s[i]==" " and i>=0:
            i-=1
        cnt=0
        while s[i]!=" " and i>=0:
            cnt+=1
            i-=1
        return cnt
        