package ROUND_1.JAVA.Optimal;

import java.io.*;
import java.util.*;

public class Energy_core_transfer {
     public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long answer = (1L << n) - 1;

        System.out.println(answer);
    }
    
}
