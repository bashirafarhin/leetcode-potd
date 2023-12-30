class Solution:
    def merge(self,nums,l,m,r):
     temp=[]
     left=l
     right=m+1
     while left<=m and right<=r:
      if nums[left]<=nums[right]:
       temp.append(nums[left])
       left+=1
      else:
       temp.append(nums[right])
       right+=1
     while left<=m:
      temp.append(nums[left])
      left+=1
     while right<=r:
      temp.append(nums[right])
      right+=1
     for i in range(l,r+1):
      nums[i]=temp[i-l]
     return nums
    def mergeSort(self,nums,l,r):
     if l>=r:
      return nums
     m=(l+r)//2
     self.mergeSort(nums,l,m)
     self.mergeSort(nums,m+1,r)
     return self.merge(nums,l,m,r)
    
    def sortArray(self, nums: List[int]) -> List[int]:
     return self.mergeSort(nums,0,len(nums)-1)