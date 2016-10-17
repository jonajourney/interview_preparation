/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.


example:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)"

example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.


Good info:

iterating over a vector in C++ :
http://stackoverflow.com/questions/409348/iteration-over-stdvector-unsigned-vs-signed-index-variable
*/

#include <iostream>
#include <algorithms>

using namespace std;

class Solution{
    public:
    int maxProfit(vector<int> & prices){
        int maxPrice=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            maxPrice = max(maxPrice, (prices[i] - minPrice));
        }

        return maxPrice;
    }
};



/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector <int> storage;
        vector <int>::iterator i,j,x;
        for(i=prices.begin(); i<prices.end();i++){
            for( j=i+1; j<prices.end();j++){
                storage.push_back(j-i);
            }
        }
        int max=0;

        for( int x=0;x<storage.size();x++){
            if(storage[x]>max){
                max = storage[x];
            }
        }

        return max;
    }
};
*/