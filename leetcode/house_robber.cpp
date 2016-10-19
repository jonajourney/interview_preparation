/*

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Notes:
This is a pretty neat dynamic programming problem.
What is dynamic programming? "dynamic" means -constant change or progress


ex) we can either take 1,3,5,7,9 th .. element OR take 2,4,6,8th....
    ORR we can also skip those >2(more than 2) adjacent house...
    so how are we gona find the best solution?
    we use:
    odd_count = max(odd_count + nums[i], even_count)  ===> when it is a house with a odd number
    even_count = max(even_count+nums[i], odd_count)  ==> when it is a house with an even number
      ..BUT WHY?
      Explanation: if you choose to start with the odd house(house n.o 1), your next step(if there is) is to
                   either choose the house number 3 or choose to switch to the "even_count track" (0+2), which also
                   indirectly means "skipping house 3" (if this track leads to a better robbery)...
*/

#include <iostream>
#include <algorithm>

using namespace std;


class Solution{
public:
  int rob(vector <int> &nums){
    int odd_count=0, even_count=0;
    for(int i=0; i<nums.size(); ++i){
      //check if it is odd or even
      if(i & 1){
        odd_count = max(odd_count+nums[i],even_count );
      }
      else{
        even_count = max(even_count+nums[i], odd_count);
      }
    }

    return max(odd_count,even_count);
  }
};
