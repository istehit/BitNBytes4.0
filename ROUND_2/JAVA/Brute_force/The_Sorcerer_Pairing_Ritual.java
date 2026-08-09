

import java.io.*;
import java.util.*;

public class The_Sorcerer_Pairing_Ritual {
     static boolean isPowerOfTwo(long x) {
        return x > 0 && (x & (x - 1)) == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] a = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPowerOfTwo(a[i] + a[j])) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
    
}
/* 
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
