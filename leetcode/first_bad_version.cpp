/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //use binary search?
        int last = n;
        int first = 0;
        int mid = (first + last) / 2;
        int previous_mid = mid;
        

        if(isBadVersion(mid)==1){
            //is bad, move last = mid;
            last = mid;
            mid = (first + last) /2;
        }
        else{
            //not bad, move to the right side;
            first = mid+1;
            mid = (first + last) /2;
        }
    }
};

class Solution {
public:
    int firstBadVersion(int n) {
        int lower =1, upper = n, mid ;
        while(lower<upper){
            mid = lower + (upper-lower) /2 ; // https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
            if(!isBadVersion(mid)) lower = mid+1;
            else upper = mid;
        }
        return lower;
    }
};

