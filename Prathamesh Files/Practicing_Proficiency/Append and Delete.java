import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the appendAndDelete function below.
    static String appendAndDelete(String s, String t, int k) {
        int s1 = s.length();
        int s2 = t.length();
        int l = 0;
        if(s.indexOf(t)==0){
            int d =s.indexOf(t);
            l=s1-s2;

        }
        else if(t.indexOf(s)==0){
            int r = t.indexOf(s);
            l=s2-s1;
        }
        else{
            for(int i=0;i<s1;i++){
                if(s.charAt(i)!=t.charAt(i)){
                    l=i;
                    break;
                }

            }
        }
        int x = l;
        int y = s1-l;
        int z = s2-l;
        if((y+z)<k || (y+z)==k){
            return "Yes";
        }
        else{
            return "No";
        }




    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String t = scanner.nextLine();

        int k = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String result = appendAndDelete(s, t, k);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}