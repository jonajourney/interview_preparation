/*
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
  int longestPalindrome(string s){
    //this solution is inspired by StefanPochmann on leetcode
    /*
    the concept of this solution is that it takes all number of characters and subtract them with the
    total odd numbers, and add 1 (for the exceptional odd number that can be included wholy)
    */

    int odds=0;
    for(char c='A'; c<='z';c++){
      odds+= count(s.begin(), s.end(),c) & 1; //if it is odd, it will add 1 to odds
    }

    return s.length() - odds + (odds>0); //(odds>0) will return 1 if odds > 0
  }
};

// class Solution{
// public:
//   int longestPalindrome(string s) {
//     int store[128];//assuming ascii. this this a "fake hash table"
//     int largest=0;
//     int res=0;
//
//     //set all to 0
//     for(int i=0;i<128; i++){
//       store[i]=0;
//     }
//
//     for(int i=0;i<s.length(); i++){
//       int val = s[i];
//       store[val]+=1;
//     }
//
//     for(int x=0;x<128;x++){
//       if(largest<store[x] && ((store[x]%2) !=0)){
//         largest = store[x];
//       }
//
//       if((store[x]%2)==0){
//         //means even, auto count in
//         res+=store[x];
//       }
//     }
//
//     res +=largest;
//
//     return res;
//   }
// };


int main(){
  Solution test;
  string s="asdfghjkinknasckbnaobsdcajbakjbdckajbsdcabacdasdcadcagwerheh";
  cout<<test.longestPalindrome(s);
}
