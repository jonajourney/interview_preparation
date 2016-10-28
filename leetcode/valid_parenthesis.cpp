  /*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
  */


#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
      bool isValid(string s) {
        stack <char> temp;
        for(char c: s){
          switch(c){
            case '(':
            case '{':
            case '[': temp.push(c); break;
            case ')': if(temp.empty()||temp.top()!='(') return false; else temp.pop(); break;
            case '}': if(temp.empty()||temp.top()!='{') return false; else temp.pop(); break;
            case ']': if(temp.empty()||temp.top()!='[') return false; else temp.pop(); break;
            default: ;

        }
      }
      return temp.empty();
  }
};
