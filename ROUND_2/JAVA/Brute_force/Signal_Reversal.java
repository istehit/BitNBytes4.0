import java.util.*;

public class Signal_Reversal {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        boolean negative = n < 0;

        String s = String.valueOf(Math.abs((long) n));

        String reversed = new StringBuilder(s).reverse().toString();

        long ans = Long.parseLong(reversed);

        if (negative)
            ans = -ans;

        if (ans < Integer.MIN_VALUE || ans > Integer.MAX_VALUE)
            System.out.println(0);
        else
            System.out.println(ans);
    }
}
/* 
Time Complexity: O(log N)
Space Complexity: O(1)
*/