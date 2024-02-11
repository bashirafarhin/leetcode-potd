import sys
class Solution:
      
    def cherryPickup(self, grid: List[List[int]]) -> int:
     row=len(grid)
     col=len(grid[0])
     dp=[[[-1 for i in range(col+1)]for j in range(col+1)]for k in range(row+1)]
     for j1 in range(col):
      for j2 in range(col):
       if j1==j2:
        dp[row-1][j1][j2]=grid[row-1][j2]
       else:
        dp[row-1][j1][j2]=grid[row-1][j1]+grid[row-1][j2]
     for i1 in range(row-2,-1,-1):
      for j1 in range(col-1,-1,-1):
       for j2 in range(col):
         maxi=-sys.maxsize
         for x in range(-1,2):
          for y in range(-1,2):
           if j1+x<0 or j1+x>col or j2+y<0 or j2+y>col:
            value=-sys.maxsize
           else:
            value=dp[i1+1][j1+x][j2+y]
           if j1==j2:
            maxi=max(maxi,value+grid[i1][j1])
           else:
            maxi=max(maxi,value+grid[i1][j1]+grid[i1][j2])
           dp[i1][j1][j2]=maxi
     return dp[0][0][col-1]
