/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total_length = m+n-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[total_length] = nums1[i];
                i--;
                total_length--;
            }
            else{
                nums1[total_length] = nums2[j];
                j--;
                total_length--;
            }
        }

        //if i>= 0, no need to change anything because nums1[i] will already be in place
        //but if does not fulfill (i>=0 && j>=0) and fullfills (j>=0) , means i==0, so fill in all remaining nums1 with the remaining nums2
        while(j>=0){
            nums1[total_length--] = nums2[j--];
        }

    }
};


/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total_length = m+n-1;
        int i = m-1;
        int j = n-1;
        vector <int> temp (nums1.begin(), nums1.end());

        for(int x=0;x<total_length;x++){
            if(temp[x]<nums2[x]) nums1[x] = temp[x];
            else nums1[x] = nums2[x]; 
        }


    }
*/