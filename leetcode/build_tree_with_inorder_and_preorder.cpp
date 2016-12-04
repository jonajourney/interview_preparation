/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Tips from geeks for geeks:
Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences. By searching ‘A’ in Inorder sequence, we can find out all elements on left side of ‘A’ are in left subtree and elements on right are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree()
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder, 0, preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* helper(vector<int> & preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[ps]); //the root node

        //locate the root node in the inorder vector. When found, the elements to the left of the root node is the left subtree and the elements in the right of the root node is the right subtree
        int pos;
        for(int x=is;x<=ie;x++){
            if(inorder[x]==node->val){
                pos = x;
                break;
            }
        }

        node->left = helper(preorder, inorder,ps+1, ps + pos - is, is, pos-1);
        node->right = helper(preorder, inorder , pe-ie+pos+1, pe, pos+1, ie);

        return node;
    }
};