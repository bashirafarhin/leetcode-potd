class Solution:
  def largestValues(self, root: TreeNode) -> List[int]:
    if not root:
      return []
    frontier, res = [root], []
    
    while frontier:
      res.append(max(n.val for n in frontier))
      new_frontier = []
      for n in frontier:
        if n.right:
          new_frontier.append(n.right)
        if n.left:
          new_frontier.append(n.left)
      
      frontier = new_frontier
    
    return res