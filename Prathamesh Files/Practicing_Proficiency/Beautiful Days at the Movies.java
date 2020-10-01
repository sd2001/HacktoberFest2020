import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class test {
    static int beautifulDays(int i, int j, int k) {
        int c =0;
        for(int x = i;x<=j;x++){
            if(Math.abs(x - reverse(x))%k==0){
                c++;
            }
        }

        return c;
    }
    static int reverse(int x){
        String a = String.valueOf(x);
        String c = new StringBuilder(a).reverse().toString();
        int b = Integer.parseInt(c);
        return b;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] ijk = scanner.nextLine().split(" ");

        int i = Integer.parseInt(ijk[0]);

        int j = Integer.parseInt(ijk[1]);

        int k = Integer.parseInt(ijk[2]);

        int result = beautifulDays(i, j, k);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}