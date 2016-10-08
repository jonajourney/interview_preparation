#include <iostream>
#include <vector>

using namespace std;

//working solutio (credits to online sources)
class Solution{
public:
  int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int i=0;i<nums.size();i++){
      ans ^= nums[i];
    }

    return ans;
  }
};

//this solution works but is not accepted by leetcode due to runtime error
class Solution2{
public:
  int singleNumber(vector<int>& nums){
    int arr[10];
    for(int i=0;i<10;i++){
      arr[i]=0;
    }

    for(int i=0;i<nums.size();i++){
      arr[nums[i]]+=1;
    }

    for(int i=0;i<nums.size();i++){
      if(arr[nums[i]]==1){
        return nums[i];
      }
    }

    return 0;
  }
};


int main(){
  Solution test;
  vector <int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(3);
  cout<<test.singleNumber(vec)<<endl;;
}
