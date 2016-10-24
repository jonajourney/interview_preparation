/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

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

 class Solution{
 public:
   int helpSum(TreeNode* root, int sum){
     //this answers my question whether i can have a constant in a recursion, apparently you can, just have to change the value in every recursion call
     int val=0;
     if(root){
       if(root->val==sum) val++;
       val += helpSum(root->left, sum-root->val);
       val += helpSum(root->right, sum-root->val);
     }
     return val;
   }

   int pathSum(TreeNode* root, int sum){
     if(root==NULL) return 0;

     return helpSum(root, sum) + pathSum(root->left,sum ) + pathSum(root->right, sum);
   }
 };

//another solution
class Solution{
public:
  int num=0;
  void dfs_counting(TreeNode* root, int sum){
    if(root==NULL) return;
    sum -=root->val;
    if(sum==0) num++;
    if(root->left) dfs_counting(root->left, sum);
    if(root->right) dfs_counting(root->right, sum);
  }

  void dfs(TreeNode* root, int sum){
    if(root==NULL) return;
    dfs_counting(root, sum);
    if(root->left) dfs(root->left, sum);
    if(root->right) dfs(root->right, sum);

  }

  int pathSum(TreeNode* root, int sum){
    dfs(root, sum);
    return num;
  }

};


 //my solution: dont know why doesnt work
 /*
 class Solution {
 public:
     int pathSum(TreeNode* root, int sum) {
       if(!helper1(root, sum)) return 0;
       if(helper1(root, sum)) return 1;

       return pathSum(root->left, sum) + pathSum(root->right, sum);
     }


     bool helper1(TreeNode * root,int sum){
       if(root==NULL) return false;
       if(root->val==sum) return true;
       if(root->val != sum && (!root->left) && (!root->right)) return false;

       return helper1(root->left, sum-root->val) || helper1(root->right, sum-root->val);
     }

 };
 */
