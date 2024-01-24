class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
     p=1
     allzero=0
     n=len(nums)
     for i in range(n):
      if nums[i]==0:
       allzero+=1
      else:
       p=p*nums[i]
   
     for i in range(n):
      if allzero>1:
       nums[i]=0
      elif allzero==1:
       if nums[i]==0:
        nums[i]=p
       else:
        nums[i]=0
      else:
       nums[i]=p//nums[i]
     return nums