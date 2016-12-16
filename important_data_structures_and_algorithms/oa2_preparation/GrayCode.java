package gray_code;

public class GrayCode {
	public static boolean isGrayCode(byte code1, byte code2){
		byte res = (byte)( code1 ^ code2);
		for(int i=0;i<=7;i++){
			byte tmp = (byte) (1 <<i);
			if(tmp == res){
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args){
		byte code1 = (byte) 2; //0000 0010
		byte code2 = (byte) 3; //0000 0011
		System.out.println(code1);
		System.out.println(code2);
		System.out.println(isGrayCode(code1,code2));
	}
}
