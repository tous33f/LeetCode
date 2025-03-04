class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        for i in range( len(haystack) ):
            print(haystack[i:i+len(needle)],needle)
            if haystack[i]==needle[0] and haystack[i:i+len(needle)]==needle:
                return i
        return -1