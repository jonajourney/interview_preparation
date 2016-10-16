/*
*/

#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        map <char, int> num;
        num['I']=1;
        num['V']=5;
        num['X']=10;
        num['L']=50;
        num['C']=100;
        num['D']=500;
        num['M']=1000;

        int ans = num[s[s.length()-1]];

        for(int x=(s.length()-2) ; x>=0;x--){
            if(num[s[x]] < num[s[x+1]]){
                ans -= num[s[x]];
            }
            else{
                ans += num[s[x]];
            }
        }

        return ans;

    }
};