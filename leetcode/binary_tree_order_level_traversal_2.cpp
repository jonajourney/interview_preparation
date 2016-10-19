/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

example:
    3
  / \
9  20
/  \
15   7

to:

[
  [15,7],
  [9,20],
  [3]
]
*/

#include <iostream>
#include <vector>

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
     vector<vector <int>> ans;
     void DFS(TreeNode* root, int level ){
       if(root==NULL) return;
       if(level == ans.size()){
         //this checks if it is a new level, if yes, create a new "level" represented by a inner vector
         ans.push_back(vector<int>());
       }

       //insert the value into the inner vector
       ans[level].push_back(root->val);
       DFS(root->left,level+1);
       DFS(root->right,level+1);

     }

     vector<vector<int>> levelOrderBottom(TreeNode* root ){
       DFS(root, 0);
       return vector<vector<int>> (ans.rbegin(), ans.rend());
     }
 };

/*
class Solution {
public:
    vector<vector <int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root, int level=0 ) {
      if(root==NULL) return ans;
      if(level == ans.size()){
        //this checks if it is a new level, if yes, create a new "level" represented by a inner vector
        ans.push_back(vector<int>());
      }

      //insert the value into the inner vector
      ans[level].push_back(levelOrderBottom(root->left, level+1));
      ans[level].push_back(levelOrderBottom(root->right,level +1));

      return ans;
    }
};

*/
