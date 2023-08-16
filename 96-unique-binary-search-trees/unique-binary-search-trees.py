class Solution(object):
    def numTrees(self, n):
     f1=1
     f2=1
     for i in range(n-1):
      f1=f1*(2*n-i)
     for i in range(n):
      f2=f2*(n-i)
     return f1//f2
