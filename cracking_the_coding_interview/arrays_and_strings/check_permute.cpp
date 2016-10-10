/*
we cann add up all the strings and compare their total sum, if equal, they are the same
*/

#include <iostream>
#include <string>

using namespace std;
bool is_permute(string a, string b);

int main(){
  string a="asdfg";
  string b="dfgsae";

  if(is_permute(a,b)){
    cout<<"they are a permutation"<<endl;
  }
  else{
    cout<<"nope they are not"<<endl;
  }

}


bool is_permute(string a, string b){
  //returns true or false regarding is A a permutation of B
  int total_a=0;
  int total_b=0;
  for(int i=0;i<a.length();i++){
    total_a+=a[i];
  }

  for(int j=0;j<b.length();j++){
    total_b += b[j];
  }

  if(total_a == total_b){
    return true;
  }
  else{
    return false;
  }
}
