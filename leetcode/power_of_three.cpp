/*
this questions just mainly test math skills
*/

#include <iostream>

using namespace std;

class Solution{
    public:
    bool isPowerOfThree(int n){
        return fmod((log10(n)/log10(3),1))==0;
    }
};
/*
class Solution {
public:
    bool isPowerOfThree(int n) {
    
        if(n==0){
            return false;
        }

        return isPowerOfThree(n/3);
    }
};
*/