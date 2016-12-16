
public class RemoveV {
	public static void removeVowel(String input){
		String compare = "aeiouAEIOU";
		String res="";
		for(int i=0;i<input.length();i++){
			if(compare.indexOf(input.charAt(i)) > -1){
				continue;
			}
			else{
				res +=input.charAt(i);
			}
		}
		
		System.out.println(res);
	}
	
	public static void main(String[] args){
		removeVowel("helloHELLOworldWORLD");
	}
}
