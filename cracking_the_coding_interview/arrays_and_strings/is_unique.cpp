#include <iostream>
#include <string>

using namespace std;
bool solve1(string input);
bool solve2(string input);

int main(){

  string test = "acdfz";

  if(solve2(test)){
    cout<<"unique!"<<endl;
  }
  else{
    cout<<"not unique!"<<endl;
  }

}

//solving using brute force -- just use an inner for loop within a for loop to compare all possibilities
//this will take O(N^2) time, not efficient
bool solve1(string input){
  for(int i=0; i< input.length();i++){
    for(int j=0; j<input.length();j++){
      if(j!=i && input[i]==input[j]){
        return false;
      }
    }
  }

  return true;
}

//try using better method
//make a boolean array of size 128 and loop through string and mark arr with char index to true;
//if there already exist a true box in the array, return false (solution from book)
bool solve2(string input){
  bool arr[128];

  //must remember to set the initial values for an array
  for (int i=0;i<128;i++){
    arr[i]=false;
  }
  for(int i=0;i<input.length(); i++){
    int val = input[i];
    // cout<<val<<endl;
    if(arr[val]){
        return false;
      }
      arr[val] = true;
    }
  return true;
}
