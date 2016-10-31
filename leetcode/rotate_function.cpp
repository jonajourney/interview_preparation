/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/


class Solution{
public:
  int maxRotateFunction(vector<int>& A){
    if(A.size()==0) return 0;
    int sum=0, iteration=0, len = A.size();
    for(int i=0;i<len;i++){
      sum += A[i];
      iteration += (A[i] * i);
    }

    int ans = iteration;
    for(int x=0;x<len;x++){
      iteration = iteration - sum + A[x-1]*len;
      ans = max(ans, iteration);
    }

    return ans;
  }
};

public int maxRotateFunction(int[] A) {
    if(A.length == 0){
        return 0;
    }

    int sum =0, iteration = 0, len = A.length;

    for(int i=0; i<len; i++){
        sum += A[i];
        iteration += (A[i] * i);
    }

    int max = iteration;
    for(int j=1; j<len; j++){
        // for next iteration lets remove one entry value of each entry and the prev 0 * k
        iteration = iteration - sum + A[j-1]*len;
        max = Math.max(max, iteration);
    }

    return max;
}
/*
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      int total=0;
      int array_length = A.size();
      for(int i=0;i<array_length-1;i++){
        total = max(total,helper_count(A) );
        cout<<"total "<<total<<endl;
        rotate(A);
      }
      return total;
    }

    int helper_count(vector<int>& temp){
      int length = temp.size();
      int temp_total=0;
      for(int i=0;i<length-1;i++){
        temp_total += (i * temp[i]);

      }
      cout<<"temp_total "<<temp_total<<endl;
      return temp_total;
    }

    vector<int> rotate(vector<int>& A){
      int store_last = A[A.size()-1];
      for(int x=A.size()-1;x>=1;x--){
        A[x] = A[x-1];
        // cout<<"x: "<<x<<" ";
        cout<<"A[x]: "<<A[x]<<" ";
      }

      A[0] = store_last;
      cout<<"A[0]: "<<A[0]<<" ";
      cout<<endl;
      return A;
    }
};
*/
