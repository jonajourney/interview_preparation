/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int rc=0,lc=0;

        TreeNode* l=root,*r=root;

        while(l){
            lc++;
            l = l->left;
        }

        while(r){
            rc++;
            r = r->right;  
        }

        if(lc==rc) return pow(2,lc)-1;

        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};