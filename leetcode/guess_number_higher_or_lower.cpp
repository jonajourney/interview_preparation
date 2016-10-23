/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

Note:
-the iterative solution is inspired by Stefan Pochmann
- learnt how to solve integer overflow using this (max-min)/2 + min to find the mid instead
*/

#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    //recursion solution
    int guessNumber(int n) {
      return helper(1,n);
    }

    int helper(int min, int max){
      int mid = (max-min)/2 + min;
      //mid = (max-min)/2 + min to take care of integer overflow
      if(guess(mid)==0) return mid;
      if(guess(mid)==1){
        //larger then the middle number
        min= mid+1;

      }
      else if(guess(max/2==-1)){
        max= mid;
      }
      return helper(min,max);
    }
};


class Solution{
public:
  int guessNumber(int n){
    int lo=1;
    int hi=n;

    while(lo<hi){
      int mid = (hi-lo)/2 + lo;
      if( guess(mid)== 1){
        lo= mid+1;
      }
      else{
        hi = mid;
      }

    }
    return lo;
  }
};

/*
solution in python, no need to take in account of integer overflow cuz python does it
def guessNumber(self, n):
       lo, hi = 1, n
       while lo < hi:
           mid = (lo + hi) / 2
           if guess(mid) == 1:
               lo = mid + 1
           else:
               hi = mid
       return lo
*/
