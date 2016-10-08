/*
Initial thoughts: 1. use a hash table
                  2. sort them and take the last extra letters
                  3. bit manipulation
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//using bit manipulation (apparently pretty important)
//got this algorithm from the discussion

class Solution{
public:
  char findTheDifference(string s, string t){
    int first=0;
    int second=0;
    char res;

    for(int i=0;i<s.length();i++){
      first +=s[i];
    }

    for(int j=0;j<t.length();j++){
      second +=t[j];
    }

    res = second-first;
    return res;
  }
};



int main(){
  Solution test;
  string s ="abcdef";
  string t="abcde";

  cout<<test.findTheDifference(s,t)<<endl;
}

// This works for only trivial test cases, needs to add the case where if have >2 repeating
// class Solution2{
// public:
//   char findTheDifference(string s, string t){
//     //use an unordered map, <char, int> means key = type char; value=int
//     unordered_map<char, int> map;
//
//     int longest=0;
//     int smaller_num=0;
//
//     for(int i=0; i<s.length(); i++){
//       map[s[i]] +=1;
//     }
//
//     for(int j=0;j<t.length();j++){
//       map[t[j]] +=1;
//     }
//
//     if(s.length()>t.length()){
//       for(int x=0;x<longest;x++){
//         if(map[s[x]]==1){
//           return s[x];
//         }
//       }
//     }
//     else{
//       for(int x=0;x<longest;x++){
//         if(map[t[x]]==1){
//           return t[x];
//         }
//       }
//     }
//
//
//
//     return 0;
//   }
// };
