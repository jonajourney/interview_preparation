/*

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

2nd *
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map <int, int> storage;
      for(auto &a : nums){
        storage[a]++;
        if(storage[a]>1){
          //has duplicate
          return true;
        }
      }
      return false;
    }
};


int main(){
  Solution test;
  static const int arr[] = {16,2,77,29};
  vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  cout<<test.containsDuplicate(vec)<<endl;
}
