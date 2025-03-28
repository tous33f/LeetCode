class Solution:
    def findMin(self, nums: List[int]) -> int:
        left=0
        right=len(nums)-1
        while(left<right):
            mid=int((left+right)/2)
            # print(nums[left],nums[mid],nums[right])
            if nums[mid]>nums[right]:
                left=mid+1
            else:
                right=mid
        return nums[right]