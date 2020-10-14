import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class x {
    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        int x = ar.length;
        int s = 0;
        ArrayList<Integer> v = new ArrayList<Integer>();
        for(int i =0;i<x;i++){
            if(v.indexOf(ar[i])<0){
                v.add(ar[i]);
            }
            return 1;
        }
        ArrayList<Integer> f = new ArrayList<Integer>();
        for (int i =0;i<v.size();i++){
            int c =0;
            for(int j=0;j<x;j++){
                if(v.get(i)==ar[j]){
                    c++;
                }
            }
            f.add(c);
        }
        int pairs =0;
        for(int i = 0;i<v.size();i++){
            pairs += f.get(i)/2;
        }
        return pairs;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
