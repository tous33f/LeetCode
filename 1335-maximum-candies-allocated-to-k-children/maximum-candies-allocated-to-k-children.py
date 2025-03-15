class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        left=0
        right=max(candies)
        while left<right:
            mid=ceil((left+right)/2)
            total=sum(floor(x/mid) for x in candies)
            if total<k:
                right=mid-1
            else:
                left=mid
        return left