/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length
*/

#include <iostream>
using namespace std;

class Solution{
public:
  int removeElement(vector<int>& nums, int val){
    int count=0;
    for(int i=0;i<nums.size();i++){
      if(nums[i]==val){
        //increase the count of the val to remove
        count++;
      }
      else{
        nums[i-count]=nums[i];
      }
    }
    return nums.size()-count;
  }
};

/*
doesnt work
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

      int length=0;
      for(int i=0; i<nums.size();i++){
        if(nums[i]==val){
          length++;
        }
        else{
          break;
        }
      }

      int pointer1 = nums[length];
      for(int i=length+1;i<nums.size();i++){
        if(nums[i]==val){
          swap_func(pointer1, nums[i]);
          length++;
        }
      }

      return length;
    }

    void swap_func(int a, int b){
      int temp = a;
      a =b;
      b=a;
    }
};
*/
