import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the encryption function below.
    static String encryption(String s) {
        StringBuffer sd = new StringBuffer();
        int l = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!= ' '){
                sd.append(s.charAt(i));
                l+=1;
            }
        }
        int l_root_floor = (int) Math.floor(Math.sqrt(l));
        int l_root_ceil = (int) Math.ceil(Math.sqrt(l));
        int r = 0;
        int c = 0;
        String y = sd.toString();
        if(l_root_ceil*l_root_floor>=l){
            r = l_root_floor;
            c = l_root_ceil;
        }
        else{
            r = l_root_floor +1;
            c = l_root_ceil;
        }
        int e = 0;
        String[][] x = new String[r][c];
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(e<l){
                    x[i][j]= String.valueOf(y.charAt(e));
                }
                e+=1;
            }
        }
        StringBuffer p = new StringBuffer();
        int f=-1;
        for(int i =0;i<c;i++){
            for(int j =0;j<r;j++){
                if(x[j][i]!=null){
                    p.append(x[j][i]);
                    f+=1;
                }
                else{
                    p.append(" ");
                    f+=1;
                }
            }
            if(p.lastIndexOf(" ")!=f){
                p.append(" ");
                f+=1;
            }
        }
        String q = p.toString();
        return q;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = encryption(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
