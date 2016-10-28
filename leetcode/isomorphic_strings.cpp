/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
logic inspired by wtsanshou on leetcode discussion
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int temp1[128]={0}, temp2[128]={0};

        for(int i=0;i<s.length();i++){
            if(temp1[s[i]]!=temp2[t[i]]) return false;
            else if(!temp1[s[i]]){
                temp1[s[i]]=i+1;
                temp2[t[i]]=i+1;
            }
        }
        return true;
    }
};