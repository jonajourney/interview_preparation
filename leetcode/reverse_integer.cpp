#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int answer=0;
        int temp =x;
        while(temp!=0){
            if (answer>INT_MAX/10|| asnwer <INT_MIN/10){
              //keep checking if answer is an int overflow
              return 0;
            }

            int mod = temp % 10;
            temp /=10;
            answer = (answer*10) + mod;
        }



        return answer;

    }
};

int main(){
  Solution test ;

  cout<<test.reverse(-2147483648)<<endl;;
}
