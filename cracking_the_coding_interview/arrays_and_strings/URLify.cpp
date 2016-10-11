/*
reminder: need to use  ' ' instead of " " if not error will occur, it is because you are comparing to a char not string when u choose input[i]
*/
#include <iostream>
#include <string>

using namespace std;
string URLify(string input, int length);

int main(){

  string input = "Mr John Smith  ";
  cout<<URLify(input,13)<<endl;
}

string URLify(string input, int length){
  string ans;
  for(int i=0; i<length;i++){
    if(input[i]==' ' && input[i+1]!=' '){
      ans+="%20";
    }
    else{
      ans+=input[i];
    }
  }

  return ans;
}
