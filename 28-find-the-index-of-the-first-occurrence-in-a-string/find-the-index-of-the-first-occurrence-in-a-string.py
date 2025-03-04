class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        lps=[0]*len(needle)
        i=1
        l=0
        while i<len(needle):
            if needle[l]==needle[i]:
                l+=1
                lps[i]=l
                i+=1
            else:
                if l==0:
                    lps[i]=l
                    i+=1
                else:
                    l=lps[l-1]
        i=0
        j=0
        print(lps)
        while i<len(haystack):
            if haystack[i]==needle[j]:
                i+=1
                j+=1
            else:
                if j==0:
                    i+=1
                else:
                    j=lps[j-1]
            if j==len(needle):
                return i-j
        return -1
        