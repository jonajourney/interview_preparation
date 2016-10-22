/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  //Solution by mzchen
  vector<vector <int>> generate(int numRows){
    vector<vector <int>> ans(numRows);

    for(int i=0;i<numRows;i++){
      ans[i].resize(i+1);
      ans[i][0] = ans[i][i] = 1;

      for(int j=1;j<i;j++){
        ans[i][j]= ans[i-1][j-1] + ans[i-1][j];
      }
    }

    return ans;
  }
};

/*
class Solution {
public:
    vector <vector <int>> ans;
    vector <int> temp;
    vector<vector<int>> generate(int numRows) {
      if(numRows==1){
        temp.push_back(1);
        return ans.push_back(temp);
      }
      if(numRows ==2){
        temp.push_back(1);
        temp.push_back(1);
        return ans.push_back(temp);
      }
      temp.push_back(1);
      ans.push_back(temp);
      temp.push_back(1);
      temp.push_back(1);
      ans.push_back(temp);

      int count=2;
      while(count!=numRows){
        temp.push_back(1);
        for(int i=0;i<ans[count].size()-1;i++){
          temp.push_back(ans[count][i]+ans[count][i+1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
        count++;
      }

      return ans;
    }
};
*/
