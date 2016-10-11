/*
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

Thoughts:
1. manage to do a recursion for all the leaves but did not know how to omit the right leaves,
went and found help from discussion forum in leetcode, this code is inspired from those answers
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  //add a paramenter "bool isleft" to check is it a left leave
    int sumOfLeftLeaves(TreeNode* root, bool isLeft=false) {
      if(!root){
        return 0;
      }

      //check if it is a leaf node
      if(!(root->left) && !(root->right)){
        //yes it is a leaf node, now check if it is a left leaf node
        if(isLeft){
          return root->val;
        }
        else{
          return 0;
        }
      }

        return sumOfLeftLeaves(root->left,true)+ sumOfLeftLeaves(root->right, false);

    }
};
