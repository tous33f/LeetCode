class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1
        while left<=right:
            mid=int((left+right)/2)
            print(nums[left],nums[mid],nums[right])
            if nums[mid]==target:
                return mid
            else:
                if (nums[mid]>nums[right] and nums[left]<=target<nums[mid]) or (nums[mid]<nums[right] and not (nums[mid]<target<=nums[right]) ):
                    right=mid-1
                else:
                    left=mid+1
        return -1