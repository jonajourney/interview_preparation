/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.


answer inspired by : https://discuss.leetcode.com/topic/17810/3-ways-implemented-in-java-binary-search-in-order-iterative-recursive
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
     int kthSmallest(TreeNode* root, int k) {
       int count = counter(root->left); //count nodes in left subtree
       if(count>=k){
         return kthSmallest(root->left,k);
       }
       else if(count+1<k){
         return kthSmallest(root->right,k-1-count);
       }
       return root->val;
     }

     int counter(TreeNode* n){
       if(n==NULL) return 0;
       return 1+ counter(n->left) + counter(n->right);
     }
 };
