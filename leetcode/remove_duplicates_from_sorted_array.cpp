/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()==0) return 0;
      if(nums.size()==1) return nums[0];

      int check=0;
      int insert_here =0;
      for(int current=1;current<nums.size();current++){
        if(nums[current]!=nums[check]){
          insert_here++;
          nums[insert_here] = nums[current];
          check = current;
        }
      }
      return insert_here+1;
    }
};


//an even better and cleaner solution from StefanPochmann
class Solution{
public:
  int removeDuplicates(vector <int> &nums){
    int i=0;
    for( int n:nums){
      if(!i || n> nums[i-1]){
        nums[i++] = n;
      }
    }
    return i;
  }
};
