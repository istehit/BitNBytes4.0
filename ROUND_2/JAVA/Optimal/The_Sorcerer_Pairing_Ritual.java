
import java.util.*;

public class The_Sorcerer_Pairing_Ritual {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] a = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        HashMap<Long, Long> freq = new HashMap<>();
        long ans = 0;

        for (long x : a) {

            for (long p = 2; p <= 2_000_000_000L; p *= 2) {
                ans += freq.getOrDefault(p - x, 0L);
            }

            freq.put(x, freq.getOrDefault(x, 0L) + 1);
        }

        System.out.println(ans);
    }
}
/* 
Time Complexity: O(n log n)
Space Complexity: O(n)
*/