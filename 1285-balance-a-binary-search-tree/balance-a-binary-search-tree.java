/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public TreeNode buildBalanceTree(int start, int end, ArrayList<TreeNode> l) {
        if (start>end) {
            return null;
        }
        int mid=(start+end)/2;
        TreeNode root=l.get(mid);
        root.left=buildBalanceTree(start, mid-1, l);
        root.right=buildBalanceTree(mid+1, end, l);
        return root;
    }

    public void inOrder(TreeNode root, ArrayList<TreeNode> l) {
        if (root == null) {
            return;
        }
        inOrder(root.left, l);
        l.add(root);
        inOrder(root.right, l);
    }

    public TreeNode balanceBST(TreeNode root) {
        ArrayList<TreeNode> l = new ArrayList<>();
        inOrder(root, l);
        return buildBalanceTree(0,l.size()-1,l);
    }
}