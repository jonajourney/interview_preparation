/*
Given an integer, write a function to determine if it is a power of two.
ans inspired from the post in : http://stackoverflow.com/questions/1804311/how-to-check-if-an-integer-is-a-power-of-3
*/

#include <iostream>

using namespace std;

class Solution{
    public:
    bool isPowerOfTwo(int n){
        if(n==0){
            return false;
        }

        while(n%2==0){
            n/=2;
        }

        return n == 1;
    }
};

//another smart solution (answer inspired by duanmeng on leetcode):

class Solution{
    public:
    bool isPowerOfTwo(int n){
        return (n>0) && ((n&(n-1))==0);
        //becuse 2==0010; 4== 0100; 8==1000...
    }
}