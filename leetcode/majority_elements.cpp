/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

self-note:
on first thought: we can use a hashtable
*/

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> storage;
      for(int i:nums){
        storage[i]+=1;
      }
      for(auto x:nums){
        if(storage[x]> (nums.size())/2){
          return x;
        }
      }
      return 0;
    }
};

//moore voting algorithm
//inspired by https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations/2

class Solution{
public:
  int majorityElement(vector<int>& nums){
    int major,counts=0, n=nums.size();
    for(int i=0;i<n;i++){
      if(!counts){
        //if counts=zero, do this:
        major=nums[i];
        counts=1;
      }
      else{
        counts+= (major==nums[i])? 1:-1;
      }
    }
    return major;
  }
}
