/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:answer inspired by fek in leetcode discussion
*/
#include <iostream>
#include <ctype.h>
#include unordered_map;

using namespace std;


class Solution{
public:
    bool isPalindrome(string s){
        int left=0, right=(int)s.size()-1 ;
        while(left<right){
            while( left < right && !isalnum(s[left] )) ++left;
            while( right > left && !isalnum(s[right])) --right;
            if((left<right) && tolower(s[left++]) != tolower(s[right--])){
                return false;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isPalindrome(string s) {
        unordered_map<char,int> keep_count;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                keep_count[i]+=1;
            }
        }
        int test =0;
        for(auto const& round : keep_count){
            if(round.second == 1){
                test+=1;
            }
            if(test>1){
                return false;
            }
        }
        return true;
        
    }
};*/