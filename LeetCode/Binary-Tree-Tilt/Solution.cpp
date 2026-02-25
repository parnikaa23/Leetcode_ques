class Solution {
    public int findTilt(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int[] result = walk(root);
        return result[1];
    }
    
    // result[0] is the sum of all node values in the subtree rooted at the `root`
    // result[1] is the sum of the tilts of all nodes in the subtree rooted at the `root`  
    private int[] walk(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }
        
        int[] left = walk(root.left);
        int[] right = walk(root.right);
        
        int subtreeSum = left[0] + right[0] + root.val;
        int tiltSum = left[1] + right[1] + Math.abs(left[0] - right[0]);
        
        return new int[]{subtreeSum, tiltSum};
    }
}