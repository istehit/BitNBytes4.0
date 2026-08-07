package ROUND_1.JAVA.Brute_force;

import java.io.*;
import java.util.*;


public class Vault_security {
public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        if (n < 0) {
            System.out.println("NO");
            return;
        }

        String s = Integer.toString(n);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            if (s.charAt(left) != s.charAt(right)) {
                System.out.println("NO");
                return;
            }

            left++;
            right--;
        }

        System.out.println("YES");
    }

    
}
/*
Time Complexity
O(d) where d is the number of digits.
Space Complexity
O(d)
*/
