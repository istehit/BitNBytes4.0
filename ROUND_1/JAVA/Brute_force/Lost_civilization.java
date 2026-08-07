package ROUND_1.JAVA.Brute_force;

import java.io.*;
import java.util.*;


public class Lost_civilization {
    static int value(char c) {

        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (i + 1 < s.length()) {

                String pair = "" + s.charAt(i) + s.charAt(i + 1);

                if (pair.equals("IV")) {
                    ans += 4;
                    i++;
                }
                else if (pair.equals("IX")) {
                    ans += 9;
                    i++;
                }
                else if (pair.equals("XL")) {
                    ans += 40;
                    i++;
                }
                else if (pair.equals("XC")) {
                    ans += 90;
                    i++;
                }
                else if (pair.equals("CD")) {
                    ans += 400;
                    i++;
                }
                else if (pair.equals("CM")) {
                    ans += 900;
                    i++;
                }
                else {
                    ans += value(s.charAt(i));
                }

            }
            else {
                ans += value(s.charAt(i));
            }
        }

        System.out.println(ans);
    }
    
}
/*
Time Complexity
O(n) where n is the length of the string.
Space Complexity
O(1)
*/
