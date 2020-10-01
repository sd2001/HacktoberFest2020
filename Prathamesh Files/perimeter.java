package com.company;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class perimeter {
    private int dimension;

    public perimeter() {
    }

    public static int getDimension() throws IOException {
        System.out.print("Please Enter Dimension(2 for 2D and 3 for 3D) = ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a =Integer.parseInt(br.readLine());
        while (a!= 2 & a!=3){
            System.out.println("You entered an Invalid DIMENSION it should be 2 or 3, Please enter valid Dimension Again");
            System.out.print("Please Enter Dimension(2 for 2D and 3 for 3D) = ");
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            int c =Integer.parseInt(r.readLine());
            a = c;
        }
        return a;
    }

    public static int getNumberPoint() throws IOException {

        System.out.print("Please Enter Number of Points(minimum 3) = ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int b =Integer.parseInt(br.readLine());
        while(b<3){
            System.out.println("You entered points less than 3, Please enter a valid number");
            System.out.print("Please Enter Number of Points(minimum 3) = ");
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            int c =Integer.parseInt(r.readLine());
            b = c;
        }
        return b;
    }
    public static int[][] get2DInput(int b) throws IOException{
        int[][] a = new int[2][b];
        for(int i = 0;i<b;i++){
            System.out.print("Please Enter X" + (i+1) + " Coordinate = ");
            BufferedReader n = new BufferedReader(new InputStreamReader(System.in));
            int x = Integer.parseInt(n.readLine());

            System.out.print("Please Enter Y" + (i+1) + " Coordinate = ");
            BufferedReader m = new BufferedReader(new InputStreamReader(System.in));
            int y = Integer.parseInt(m.readLine());

            a[0][i] = x ;
            a[1][i] = y ;

            System.out.println("Your Coordinates for " + (i+1) + " Example are = " + x + " and " + y);
        }
        return a ;

    }
    public static int[][] get3DInput(int b) throws IOException{
        int[][] a = new int[3][b];
        for(int i = 0;i<b;i++){
            System.out.print("Please Enter X" + (i+1) + "  Coordinate = ");
            BufferedReader n = new BufferedReader(new InputStreamReader(System.in));
            int x = Integer.parseInt(n.readLine());

            System.out.print("Please Enter Y" + (i+1) + "  Coordinate = ");
            BufferedReader m = new BufferedReader(new InputStreamReader(System.in));
            int y = Integer.parseInt(m.readLine());

            System.out.print("Please Enter Z" + (i+1) + "  Coordinate = ");
            BufferedReader o = new BufferedReader(new InputStreamReader(System.in));
            int z = Integer.parseInt(o.readLine());

            a[0][i] = x ;
            a[1][i] = y ;
            a[2][i] = z ;

            System.out.println("Your Coordinates for " + (i+1) + " Example are = " + x + " , " + y + " and " + z);
        }
        return a ;

    }

    public static double get2DPerimeter(int[][] a,int b){
        double perimeter = 0;
        for(int i=0;i<b-1;i++){
            int x1 = a[0][i];
            int x2 = a[0][i+1];
            int y1 = a[1][i];
            int y2 = a[1][i+1];

            double distance = Math.sqrt(Math.pow((x1-x2),2) + Math.pow((y1-y2),2));
            perimeter+=distance;
        }
        int l = b-1;
        int xl = a[0][l];
        int yl = a[1][l];
        int xb = a[0][0];
        int yb = a[1][0];
        perimeter+= Math.sqrt(Math.pow((xl-xb),2) + Math.pow((yl-yb),2));

        return perimeter;

    }

    public static double get3DPerimeter(int[][] a,int b){
        double perimeter = 0;
        for(int i=0;i<b-1;i++){
            int x1 = a[0][i];
            int x2 = a[0][i+1];
            int y1 = a[1][i];
            int y2 = a[1][i+1];
            int z1 = a[2][i];
            int z2 = a[2][i++];

            double distance = Math.sqrt(Math.pow((x1-x2),2) + Math.pow((y1-y2),2)+Math.pow((z1-z2),2));
            perimeter+=distance;
        }
        int l = b-1;
        int xl = a[0][l];
        int yl = a[1][l];
        int zl = a[2][l];
        int xb = a[0][0];
        int yb = a[1][0];
        int zb = a[2][0];
        perimeter+= Math.sqrt(Math.pow((xl-xb),2) + Math.pow((yl-yb),2) + Math.pow((zl-zb),2));

        return perimeter;
    }
}
