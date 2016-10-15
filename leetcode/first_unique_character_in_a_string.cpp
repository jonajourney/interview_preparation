/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

example:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map <char, int> storage;
      for(auto &c:s){
        storage[c]+=1;
      }

      for(int i=0; i<s.size();i++){
        if(storage[s[i]] ==1){
          return i;
        }
      }

      return -1;
    }
};

/*
class Solution {
public:
    int firstUniqChar(string s) {
      for(int i=0;i<s.length();i++){
        if(count(s.begin(),s.end(),s[i]) == 1){
          return i;
        }
      }
      return -1;
    }
};
*/

int main(){

}
