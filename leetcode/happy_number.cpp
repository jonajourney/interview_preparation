/*
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number either equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers, 
while those that do not end in 1 are unhappy numbers (or sad numbers)

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

/*
this solution uses the Floyd cycle detection algorithm:
see more here: https://www.quora.com/How-does-Floyds-cycle-finding-algorithm-work

explaination:
-If it is a happy number than it will stay at one and the slow pointer will eventually catch up
-Very clever idea. Whether the number is or not, its square sum sequence is always a list with cycle

why is the square sum sequence be a cycle?
explain: 
1. https://discuss.leetcode.com/topic/30520/explanation-of-why-those-posted-algorithms-are-mathematically-valid
2. https://discuss.leetcode.com/topic/42746/all-you-need-to-know-about-testing-happy-number

other resources:
https://discuss.leetcode.com/topic/38728/0ms-c-solution-beats-97-4-perhaps-the-most-easy-one-to-understand

*/

#include <iostream>

class Solution{
    public:
    bool isHappy(int n){
        int p1=n;
        int p2 = next(n);

        while(p1!=p2){
            p1 = next(p1);
            p2 = next(next(p2));
        }

        return p1==1;
    }

    int next(int n){
        //sum of all the digits (squares each digit)
        int res=0;
        while(n){
            int temp = n%10;
            res += temp * temp;
            n/=10;
        }

        return res;
    }
};