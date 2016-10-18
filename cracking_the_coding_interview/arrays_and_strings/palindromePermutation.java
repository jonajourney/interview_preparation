
import java.util.HashMap;

public class palindromePermutation{

  public boolean isPermutationOfPalindrome(String input){
    int [] table = buildCharFrequencyTable(input);
    return checkMaxOneOdd(table);
  }

  public int [] buildCharFrequencyTable(String input){
    int [] table =new int[Character.getNumericValue('z') - Character.getNumericValue('a')+1];
    for(char c:input.toCharArray()){
      int x=getCharNumber(c);
      if(x!=-1){
        table[x]++;
      }
    }
    return table;
  }

  public boolean checkMaxOneOdd(int[] table){
    boolean foundOdd = false;
    for(int count:table){
      if(count%2 == 1){
        //found odd
        if(foundOdd){
          return false;
        }
        foundOdd=true;
      }
    }
    return true;
  }

  public int getCharNumber(Character c){
    int a = Character.getNumericValue('a');
    int z = Character.getNumericValue('z');
    int val = Character.getNumericValue(c);
    if(a <=val && val<=z){
      return val - a;
    }
    return -1;
  }

  public static void main(String[] args){
    palindromePermutation tester = new palindromePermutation();
    String test="taco asm";
    System.out.println(tester.isPermutationOfPalindrome(test));
  }


}
