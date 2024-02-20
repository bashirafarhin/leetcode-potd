class Solution:
    def missingNumber(self, nums: List[int]) -> int:
     n=len(nums)
     s=sum(nums)
     intsum=n*(n+1)//2
     if intsum==s:
      return 0
     return abs(intsum-s)