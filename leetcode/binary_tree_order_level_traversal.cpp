/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Note:
This solution is similar with binary tree order level bottom , but without reversiing in the end
*/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> storage; //this vector stores vector according to their levels
    void DFS(TreeNode* root,int level){
      if(root==NULL) return ;
      if(level==storage.size()){
        storage.push_back(vector<int>());
      }

      storage[level].push_back(root->val);
      DFS(root->left,level+1);
      DFS(root->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      DFS(root,0);
      return storage;
    }

};

//a queue implementation (just because it will be good to know both)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> storage;
      if(!root) return storage;
      queue<TreeNode*>q;
      //push in the head and a null behind the head
      q.push(root);
      q.push(NULL);
      vector<int> temp; //this is to create a "new" vector inside the vector when reach a new level
      while(!q.empty()){
        TreeNode* t= q.front();
        q.pop();
        if(t==NULL){
          //push in storage vector and create a new vector inside the storage vector;
          storage.push_back(temp);
          temp.resize(0);
          if(q.size()>0){
            q.push(NULL);
          }
        }
        else{
          temp.push_back(t->val);
          if(t->left) q.push(t->left);
          if(t->right)q.push(t->right);
        }
      }


      return storage;
    }

};
