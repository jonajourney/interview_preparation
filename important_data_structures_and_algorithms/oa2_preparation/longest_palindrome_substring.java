/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
Subscribe to see which companies as

Note: answer from : https://discuss.leetcode.com/topic/23498/very-simple-clean-java-solution/2
*/

public class Solution {
    private int low, max;
    public String longestPalindrome(String s) {
        if(s.length()-1 <2){
            return s;
        }
        
        for(int i=0;i<s.length()-1;i++){
            helper(s,i,i);
            helper(s,i,i+1); //if even, meaning the most center has 2 same , not sharing single char
        }

        return s.substring(low,low+max);
    }
    
    public void helper(String s, int left, int right){
        while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
            left--;
            right++;
        }

        if(max < right-left-1){
            //it went further then the previous one
            low = left+1;
            max = right-left-1;
        }
    }
}