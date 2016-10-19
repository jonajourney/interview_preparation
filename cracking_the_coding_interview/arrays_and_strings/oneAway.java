
class oneAway{
  boolean driverFunction(String in, String out){
    if(in.length()- out.length() >=2){
      return false;
    }

    int []temp = buildCharFrequencyTable(in,out);
    return checkNotMoreThanOne(temp);
  }

  int [] buildCharFrequencyTable(String in, String out){
    int[] table = new int[Character.getNumericValue('z')-Character.getNumericValue('a')+1];
    for(char c: in.toCharArray()){
      int x = getCharNumber(c);
      table[x]+=1;
    }
    for(char c: out.toCharArray()){
      int x = getCharNumber(c);
      table[x]+=1;
    }
    return table;
  }

  int getCharNumber(Character c){
    int a = Character.getNumericValue('a');
    int z = Character.getNumericValue('z');
    int val = Character.getNumericValue(c);

    if(a<=val && val<=z){
      return val-a;
    }
    return -1;
  }

  boolean checkNotMoreThanOne(int [] inputArr){
    int single=0;
    for(int i=0;i<inputArr.length;i++){
      if(inputArr[i]==1){
        single+=1;

      }


      if(single>=2){
        return false;
      }
    }
    return true;
  }

  public static void main(String []args){

    oneAway tester = new oneAway();
    String in="pale";
    String out="bake";
    System.out.println(tester.driverFunction(in,out));
  }


}
