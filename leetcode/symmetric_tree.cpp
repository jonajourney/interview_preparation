/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

Note:
solved completely by myself, but after reading the editorial, realize there is much better method:
JUST COMPARE THE ROOT RECURSIVELY
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
     vector<int>left_store;
     vector<int>right_store;
     bool isSymmetric(TreeNode* root) {
       DFS_left(root);
       DFS_right(root);

       return left_store==right_store;
     }

     void DFS_left(TreeNode* root){
       if(root==NULL){
         left_store.push_back(0);
         return;
       }
       left_store.push_back(root->val);
        DFS_left(root->left);
        DFS_left(root->right);

     }

     void DFS_right(TreeNode* root){
       if(root==NULL){
         right_store.push_back(0);
         return;
       }

       right_store.push_back(root->val);
        DFS_right(root->right);
        DFS_right(root->left);

     }
 };


class Solution {
public:
    vector<int>left_store;
    vector<int>right_store;
    bool isSymmetric(TreeNode* root) {
      // return DFS_left(root) == DFS_right(root);
      DFS_left(root);
      DFS_right(root);

      return left_store==right_store;
    }

    void DFS_left(TreeNode* root){
      if(root==NULL){
        left_store.push_back(0);
        return;
      }
      // if(root->left==NULL && root->right==NULL) return root;
      left_store.push_back(root->val);
       DFS_left(root->left);
       DFS_left(root->right);
      //  return root;
    }

    void DFS_right(TreeNode* root){
      if(root==NULL){
        right_store.push_back(0);
        return;
      }
      // if(root->left==NULL && root->right==NULL) return root;
      right_store.push_back(root->val);
       DFS_right(root->right);
       DFS_right(root->left);
      //  return root;
    }
};
