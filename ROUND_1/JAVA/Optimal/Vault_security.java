import java.io.*;
import java.util.*;

public class Vault_security {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // Negative numbers are never palindromes
        if (n < 0) {
            System.out.println("NO");
            return;
        }

        int original = n;
        int reverse = 0;

        while (n != 0) {

            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n /= 10;
        }

        if (reverse == original)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
    
}
/*
Time Complexity
O(log10 N)
Space Complexity
O(1)
*/
