/*

got soluition from leetcode
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution{
public:
  vector<int> intersect(vector<int>& a, vector<int>& b){
    unordered_map <int ,int> store;
    vector <int> res;
    for(int i=0;i<a.size();i++){
      store[a[i]]++;
    }

    for(int x=0;x<b.size();x++){
      //this part i missed out myself
      if(store.find(b[i])!=store.end() && store[b[x]]>0){
        //there is intersection
        res.push_back(b[x]);
        store[b[i]]--;
      }
    }

    return res;
  }
};


int main(){

}
