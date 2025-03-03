class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        pool = {
        1:    'I',
        4:    'IV',
        5:    'V',
        9:    'IX',
        10:    'X',
        40:    'XL',
        50:    'L',
        90:    'XC',
        100:    'C',
        400:    'CD',
        500:    'D',
        900:    'CM',
        1000:    'M'
        }
        ans=""
        while(num>0):
            li=list(sorted(pool.keys()))[::-1]
            print(li)
            for i in li:
                if num-i>=0:
                    div=i
                    break
            ans+="".join([pool[div]]*(int(num/div)))
            num=num%div
        return ans
        
        