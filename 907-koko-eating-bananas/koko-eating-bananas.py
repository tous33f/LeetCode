class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left=1
        right=max(piles)
        while left<right:
            mid=int((left+right)/2)
            # print(left,mid,right)
            t=0
            for pile in piles:
                if pile<mid:
                    t+=1
                else:
                    t+=ceil(pile/mid)
                # print(ceil(pile/mid),pile)
            # print(t)
            if t>h:
                left=mid+1
            else:
                right=mid
        return left