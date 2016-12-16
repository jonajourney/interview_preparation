package shortest_word_distance;

public class ShortestDistance {
	public static int distance(String[] words, String word1, String word2){
		int len = words.length;
		int m=-1;
		int n=-1;
		int min = Integer.MAX_VALUE;
		for(int i=0;i<len;i++){
			String s = words[i];
			if(word1.equals(s)){
				m=i;
				if(n!=-1){
					min = Math.min(min, m-n);
				}
			}
			else if(word2.equals(s)){
				n=i;
				if(m!=-1){
					min = Math.min(min, n-m);
				}
			}
		}
		return min;
	}
	
	public static void main(String[] args){
		String[] myarr={"hello", "this", "beautiful","nice", "world"};
		System.out.println(distance(myarr, "hello", "world"));
	}
}
