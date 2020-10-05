/*
 * Java Program to find no. of UpperCase in a String.
 * By @shivamjaiswal64
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

class noOfUpperCase{	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] ch = br.readLine().toCharArray();
		int res =0;
			for (int i=1;i<ch.length;i++ ) {
				if(Character.isUpperCase(ch[i]))
					res++;
			}
			System.out.println("No. of UpperCase: "+res);
	}
}
