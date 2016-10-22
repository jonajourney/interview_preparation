/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

  1
/   \
2     3
\
5

["1->2->5", "1->3"]

Note:
-Remember to pass by reference!!
-a note for recursive solution: you can add in "previous" states to the recursive call if u want to print out the whole path
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
     void helper(vector<string>& storage, TreeNode* root, string input){
       if(root->left==NULL && root->right==NULL) {
         storage.push_back(input);
         return;
       }
       if(root->left) helper(storage,root->left, input +"->" + to_string(root->left->val));
       if(root->right) helper(storage,root->right, input +"->" + to_string(root->right->val));
     }
     vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
       if(root==NULL) return ans;
       helper(ans, root, to_string(root->val));

       return ans;
     }
 };
