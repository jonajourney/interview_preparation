/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
self note: 
on first glance, this looks like a backtracking algorithm to me

example:
if 3x3 :  [ [1,3,6]
            [6,11,8]
            [2,1,9]  ]

the minimum path would be 1->6->2->1->9 ?

Trying brute force:
using 2 for loops : can we even do it?

Turns out:
DP problem

*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
    }
};