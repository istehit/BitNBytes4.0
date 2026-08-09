import java.util.*;

public class Signal_Reversal {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long rev = 0;

        while (n != 0) {

            int digit = n % 10;

            rev = rev * 10 + digit;

            n /= 10;
        }

        if (rev < Integer.MIN_VALUE || rev > Integer.MAX_VALUE)
            System.out.println(0);
        else
            System.out.println(rev);
    }
}
/* 
Time Complexity: O(log N)
Space Complexity: O(1)
*/