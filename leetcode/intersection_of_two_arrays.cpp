/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

   Each element in the result must be unique.
   The result can be in any order.

*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
  vector <int> intersection(vector <int>& nums1, vector<int>& nums2){
    unordered_set<int> temp(nums1.begin(),nums1.end());
    vector <int> ans;

    for( auto a:nums2){
      if(temp.count(a)){
        ans.push_back(a);
        temp.erase(a);
      }
    }

    return ans;
  }
};

int main(){

}
