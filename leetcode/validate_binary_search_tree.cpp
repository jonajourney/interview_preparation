/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Note:
remember to cover the case for long numbers; so use LONG_MIN and LONG_MAX instead
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

 #include <iostream>
 #include <limits.h>

 using namespace std;
 class Solution {
 public:
     bool isValidBST(TreeNode* root) {
         return helper(root, LONG_MIN,  LONG_MAX);
     }
     bool helper(TreeNode* root, long min, long max){
         if(root==NULL) return true;
         if(root->val <= min || root->val >= max){
             return false;
         }

         return helper(root->left, min, root->val) && helper(root->right, root->val, max);
     }
 };
