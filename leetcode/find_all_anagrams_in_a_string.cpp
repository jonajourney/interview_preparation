/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

example:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  vector<int> findAnagrams(string s, string p){
      vector <int> res;
      if (s == null || s.length() == 0 || p == NULL || p.length() == 0) return res;
      int store[256];

      for(int i=0;i<256;i++){
        store[i]=0;
      }

      for(int i=0;i<p.length();i++){
        int temp = p[i];
        store[temp] ++;
      }

      int left=0, right=0, count=p.length();

      while(right<s.length()){
        if(store[s[right]]>=1){
          right++;
          count--;
          store[s[right]]--;
        }

        if(count==0){
          res.push_back(left);
        }

        if(right-left==p.length() && (store[s[left]]>=0) ){
          count++;
          left++;
          store[s[left]] ++;
        }
      }
      return res;
  }
};

public List<Integer> findAnagrams(String s, String p) {
    List<Integer> list = new ArrayList<>();
    if (s == null || s.length() == 0 || p == null || p.length() == 0) return list;
    int[] hash = new int[256]; //character hash
    //record each character in p to hash
    for (char c : p.toCharArray()) {
        hash[c]++;
    }
    //two points, initialize count to p's length
    int left = 0, right = 0, count = p.length();
    while (right < s.length()) {
        //move right everytime, if the character exists in p's hash, decrease the count
        //current hash value >= 1 means the character is existing in p
        if (hash[s.charAt(right++)]-- >= 1) count--;

        //when the count is down to 0, means we found the right anagram
        //then add window's left to result list
        if (count == 0) list.add(left);

        //if we find the window's size equals to p, then we have to move left (narrow the window) to find the new match window
        //++ to reset the hash because we kicked out the left
        //only increase the count if the character is in p
        //the count >= 0 indicate it was original in the hash, cuz it won't go below 0
        if (right - left == p.length() && hash[s.charAt(left++)]++ >= 0) count++;
    }
    return list;
}
/*
//not a good solution because the logic has major bugs
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      int charSum=0;
      vector<int> res;

      for(int i=0; i<p.length();i++){
        int temp = p[i];
        charSum +=temp;
      }

      int stringLength= p.length();
      for(int i=0;i<s.length()-p.length();i++){
        int counter = stringLength;
        int temp_count=0;
        while(counter){
          int temp = s[i];
          temp_count +=temp;
          counter--;
        }
        if(temp_count == charSum){
          res.push_back(i);
        }
      }

      return res;

    }
};

int main(){
  string s="cbaebabacd";
  string p="abc";
  Solution test;
  test.findAnagrams(s,p);
}
*/
