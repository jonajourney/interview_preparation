
/*
Use binary search.

n * m matrix convert to an array => matrix[x][y] => a[x * m + y]

an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/

public class Solution{
    public boolean searchMatrix(int[][]matrix, int target){
        if(matrix.length==0 || matrix==null){
            return false;
        }
        int start=0;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int end = rows*cols-1;

        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[mid/cols][mid%cols]==target){
                return true;
            }
            else if(matrix[mid/cols][mid%cols]<target){
                start = mid+1;
            }
            else{
                
                end = mid-1;
            }
        }
        return false;
    }
}