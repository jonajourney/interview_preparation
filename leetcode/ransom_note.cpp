/*
Given  an arbitrary  ransom  note  string and another string containing letters from  all the magazines,  write a function that will return true if the ransom  note can be constructed from the magazines ; otherwise, it will return false.  

Each letter  in  the  magazine string can  only be  used once  in  your ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

example:
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

**first time got right on one go!! :)

*/

#include <iostream>
#include <algorithm>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      if(ransomNote.length() > magazine.length()){
        return false;
      }

      for(char c='A';c<'z';c++){
        if((count(magazine.begin(), magazine.end(),c) - count(ransomNote.begin(),ransomNote.end(),c)) < 0){
          return false;
        }
      }

      return true;
    }
};
