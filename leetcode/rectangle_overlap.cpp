/*
http://www.geeksforgeeks.org/find-two-rectangles-overlap/
*/

struct Point{
    int x,y;
};

class Solution{
    public:
    bool doOverlap(Point l1,Point r1, Point l2, Point r2){
        if(l1.x > r2.x || l2.x >r1.x) return false;

        if(l1.y < r2.y || l2.y < 11.y) return false;

        return true;
    }
}