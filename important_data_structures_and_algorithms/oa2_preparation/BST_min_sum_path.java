/*
Given a binary tree, find the min path sum. The path may start and end at any node in the tree.
*/

public class Solution{
    public int pathSum(TreeNode root){
        if(root==null) return 0;
        
        if(root.left==null && root.right!=null){
            //go to the right path
            return pathSum(root.right) + root.val;
        }
        if(root.right==null && root.left!=null){
            return pathSum(root.left) + root.val;
        }
        return Math.min(pathSum(root.left),pathSum(root.right)) + root.val;
}

