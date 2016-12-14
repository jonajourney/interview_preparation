package rotateString;
import java.lang.String;

public class RotateString{
    public static boolean isRotation(String s1, String s2){
        
        if(s1.length()==0 || s2.length()==0 ||s2.length()!=s1.length()|| s1==null || s2==null){
            return false;
        }

        String temp = s1+s1;

        return temp.indexOf(s2) !=-1? true:false;
    }

    public static void main(String[] args){
//        RotateString test= new RotateString();
        System.out.println(RotateString.isRotation("abaa","baaa")) ;
    }
}
