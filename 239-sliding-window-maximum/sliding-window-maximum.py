class Solution(object):
    def maxSlidingWindow(self, nums, k):
     ans=[]
     dq=deque()
     n=len(nums)
     for i in range(k):
      while dq and nums[i]>=nums[dq[-1]]:
       dq.pop()
      dq.append(i)
      
     for i in range(k,n):
      ans.append(nums[dq[0]])
      #push incoming ele
      while dq and nums[i]>=nums[dq[-1]]:
        dq.pop()
      dq.append(i)
      #remove ele from previous window
      while dq and dq[0]<=i-k:
       dq.popleft()
     
    #  add max of last window
     ans.append(nums[dq[0]])
     return ans