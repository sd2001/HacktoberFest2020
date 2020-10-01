package com.company;

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        perimeter a = new perimeter();
        int x = a.getDimension();
        int y = a.getNumberPoint();
        if(x==2){
            double z = a.get2DPerimeter(a.get2DInput(y),y);
            System.out.println("Your 2 Dimensional Perimeter for "+ y + " Points is: " + z);
        }
        else{
            double z = a.get3DPerimeter(a.get3DInput(y),y);
            System.out.println("Your 3 Dimensional Perimeter for "+ y + " Points is: " + z);

        }
    }
}
