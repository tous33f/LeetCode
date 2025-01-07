class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        res=[]
        for word_i in words:
            flag=0
            for word_j in words:
                if word_j==word_i:
                    continue
                for c in range(len(word_j)):
                    if word_i==word_j[c:c+len(word_i)]:
                        res.append(word_i)
                        flag=1
                        break
                if flag:
                    break
        return res
        