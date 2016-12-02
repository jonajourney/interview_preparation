/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.

Node:
1. at first glance, binary search seems to be fine
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n= matrix[0].size();
      int r=0, c=n-1;

      while(r<m && c>=0){
        if(matrix[r][c]==target) return true;
        else if (matrix[r][c]> target) c--;
        else r++;
      }
      return false;
    }
};
