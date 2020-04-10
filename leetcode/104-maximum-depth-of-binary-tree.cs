/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int MaxDepth(TreeNode root) {
        if (null == root) return 0;
        int l = MaxDepth(root.left) + 1;
        int r = MaxDepth(root.right) + 1;
        return l > r ? l : r;
    }
}