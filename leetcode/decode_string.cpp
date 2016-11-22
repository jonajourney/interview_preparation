/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

first take:
1. hard hard lai (brute force)
  - just use 2 indicators and iterate the array, finding the "[" sign and taking the value before is X value behind it

2.turns out its way harder then i thought, we need to use recursive method to print for an example this: 3[a2[b]] == abbabbabb

PLEASE TRY DOING IT AGAGIN..this is a pretty hard one
*/

class Solution{
public:
  string helper(string s,int& i){
    string res;

    while(i<s.length() && s[i]!=']'){
      if(!isdigit(s[i])){
        //if it not a digit(means it is an letter, add it in res)
        res += s[i++];
      }
      else{
        //if it is a digit
        int counter =0;
        while(i<s.length() && isdigit(s[i])){
          counter = counter*10 + (s[i++]-'0');
        }
        i++;
        string t = helper(s,i);
        i++;

        while(counter-->0){
          res+=t;
        }
      }
    }
    return res;
  }
  string decodeString(string s){
    int i=0;
    return helper(s,i);
  }
};

/*
class Solution {
public:
    string decodeString(string s) {
        int length = s.length(), counter=0, cur1=0,cur2=1;
        string ans="";
        while(counter!=length){
          string temp_store="";
          if(s[cur2]=='['){
            //found the opening brackets
            int mul = s[cur1]-'0';
            cur1+=2;
            cur2+=2;
            while(s[cur2]!=']'){
              temp_store.append(s[cur1]);
              cur1++;
              cur2++;
            }
            ans.append(mul,temp_store);
          }
          cur1++;
          cur2++;
        }
        return ans;
    }
};
*/
