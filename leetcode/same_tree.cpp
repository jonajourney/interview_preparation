/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

#include <iostream>
#include <string>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
          return true;
        }
        else if(p==NULL || q==NULL){
          return false;
        }

        if((p->val != q->val)){
          //i made a mistake here, instead of doing p->val == q->val , i did a (p->left == q->left)..which is pretty stupid lol
          return false;
        }

        //recurse
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};


int main(){

}
