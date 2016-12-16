/*
 example: 
[4, 2, 73, 11, -5] and window size 2 should return [6, 75, 84, 6].
 */
package window_sum;
import java.util.Arrays;

public class WindowSum {
	public static int[] findSum(int[]inputArr, int winSize){
		int[] res = new int[inputArr.length - winSize+1];
		
		//do some error checking and corner case handling here
		if(inputArr==null || winSize > inputArr.length || winSize<=0 ) return null;
		
		for(int i=0;i<winSize;i++){
			//adding the first "winSize" sized elements to the first slot in res integer array.
			res[0] += inputArr[i];
		}
		
		for(int i=1;i<res.length;i++){
			//shifting the window and adding it up and putting in res array.
			res[i] += res[i-1] - inputArr[i-1] + inputArr[i+winSize-1]; //i+winSize means shifting the window i times and -1 cuz index start from 1
		}
		
		return res;
	}
	
	public static void main(String[] args){
		int[] inputArr = new int[] {4,2,73,11,-5};
		System.out.println(Arrays.toString(findSum(inputArr,4)));
	}
}
