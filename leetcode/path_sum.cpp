/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,
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

 //did myself
class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)return false;
    if(sum==0 && (!root->left) && (!root->right)) return true;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum-root->val);
  }

    void helper (TreeNode* root, int total, int sum){
      if(root==NULL) return false;
      if(total==sum && (!root->left) && (!root->right)) return true;

      if(root->left) return hasPathSum(root->left, sum - root->val);
      if(root->right) return hasPathSum(root->right, sum-root->val);
    }
    }
};

//solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)return false;
    if(root->val==sum && (root->left==NULL) && (root->right==NULL)) return true;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum-root->val);
  }
};
