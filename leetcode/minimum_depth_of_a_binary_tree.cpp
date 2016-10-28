/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include <iostream>

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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);

        return 1+ (min(left,right)? min(left,right): max(left,right));
    }


};

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        int length=0;
        if(root==NULL) return length;

        return 1+ (minDepth(root->left)<minDepth(root->right))? length += minDepth(root->left) : length+=minDepth(root->right);
    }


};
/
