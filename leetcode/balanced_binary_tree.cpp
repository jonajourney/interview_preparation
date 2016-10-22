/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

help from : https://discuss.leetcode.com/topic/7798/the-bottom-up-o-n-solution-would-be-better/2
*/

#include <iostream>
#include <math>
#include <algorithm>
using namespace std;

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
    int depth(TreeNode * root){
      if(root==NULL) return 0;

      return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
      if(root==NULL) return true;
      int left = depth(root->left);
      int right = depth(root->right);
      return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
