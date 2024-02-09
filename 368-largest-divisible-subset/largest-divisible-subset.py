class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
     nums.sort()
     n=len(nums)
     maxlcsi=0
     maxlcs=1
     temp=[i for i in range(n)]
     dp=[1 for i in range(n)]
     for i in range(1,n):
      for prev in range(i):
       if nums[i]%nums[prev]==0 and dp[i]<dp[prev]+1:
         dp[i]=dp[prev]+1
         temp[i]=prev
      if maxlcs<dp[i]:
       maxlcsi=i
       maxlcs=dp[i]
     li=[nums[maxlcsi]]
     while temp[maxlcsi] !=maxlcsi:
      maxlcsi=temp[maxlcsi]
      li.append(nums[maxlcsi])
     li.reverse() 
     return li