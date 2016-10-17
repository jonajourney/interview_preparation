/*
Problem Statement: You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

solution help:
https://discuss.leetcode.com/topic/5371/basically-it-s-a-fibonacci

this can be solved with fibonacci sequence because for n=1; only 1 solution and n=2 only 2 solution,
so if n=3 : solution = 1+2=3 ; n=4: solution : 3+2 =5....
*/

#include <iostream>

using namespace std;

class Solution{
    public:
    int climbStairs(int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        int ans = 0;
        int two_steps_before = 1;
        int one_step_before = 2;

        for(int i=2; i<n; i++){
            ans = two_steps_before + one_step_before;
            two_steps_before = one_step_before;
            one_step_before = ans;
        }

        return ans;

    }
};