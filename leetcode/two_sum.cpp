/*
Comments: Pretty straight forward strateg, just need to know how to use the vector STL in C++
*this includes a working test example
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int> &nums, int target){
    vector<int> answer;
    for(int i=0;i<nums.size();i++){
      for(int j=i+1;j<nums.size();j++){
        if(nums[i]+nums[j]==target){
          answer.insert(answer.end(),i);
          answer.insert(answer.end(),j);
        }
      }
    }

    return answer;
  }

  void printout(vector<int>input){
    for(int i=0;i<input.size();i++){
      cout<<input[i];
    }
    cout<<endl;
  }
};

int main(){
  vector<int> test;
  Solution tester;
  test.push_back(2);
  test.push_back(7);
  test.push_back(11);
  test.push_back(15);

  tester.printout(tester.twoSum(test,9));
}
