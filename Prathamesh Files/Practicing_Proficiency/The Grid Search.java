import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gridSearch function below.
    static String gridSearch(String[] G, String[] P) {
        int g_l = G.length;
        int p_l = P.length;
        int p =0;
        int c;
        int y1;
        int y2;
        for(int i =0;i<g_l;i++){
            if(i+p_l<=g_l){
                if(G[i].lastIndexOf(P[0])>=0 || G[i].indexOf(P[0])>=0){
                    c =1;
                    y1 =0;
                    y2 =0;
                    y1 = G[i].lastIndexOf(P[0]);
                    y2 = G[i].indexOf(P[0]);
                    for (int j = i+1;j<p_l+i;j++){
                        if(G[j].lastIndexOf(P[j-i])>=0 || G[j].indexOf(P[j-i])>=0 ){
                            if(G[j].lastIndexOf(P[j-i])==y1 || G[j].lastIndexOf(P[j-i])==y2){
                                c+=1;
                                p=c;
                            }
                        }
                    }

                }
            }
        }
        if (p==(p_l)){
            return "YES";
        }
        else {
            return "NO";
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] RC = scanner.nextLine().split(" ");

            int R = Integer.parseInt(RC[0]);

            int C = Integer.parseInt(RC[1]);

            String[] G = new String[R];

            for (int i = 0; i < R; i++) {
                String GItem = scanner.nextLine();
                G[i] = GItem;
            }

            String[] rc = scanner.nextLine().split(" ");

            int r = Integer.parseInt(rc[0]);

            int c = Integer.parseInt(rc[1]);

            String[] P = new String[r];

            for (int i = 0; i < r; i++) {
                String PItem = scanner.nextLine();
                P[i] = PItem;
            }

            String result = gridSearch(G, P);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}