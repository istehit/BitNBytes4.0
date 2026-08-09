
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

            int curr = value(s.charAt(i));

            if (i + 1 < s.length() && curr < value(s.charAt(i + 1))) {
                ans -= curr;
            } else {
                ans += curr;
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
