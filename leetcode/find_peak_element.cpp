/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      return helper(nums,0, nums.size()-1);
    }

    int helper(vector<int>& nums, int low, int high){
      if(low==high) return low;
      else{
        int mid1 = (high-low)/2 + low;
        int mid2 = mid1+1;

        if(nums[mid1]<nums[mid2]){
          return helper(nums,mid2, high);
        }
        else{
          return helper(nums,low,mid1);
        }
      }
    }
};
