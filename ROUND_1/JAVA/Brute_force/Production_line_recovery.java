
import java.io.*;
import java.util.*;


public class Production_line_recovery {
     static boolean isSorted(int[] arr) {

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }

        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        if (isSorted(arr)) {
            System.out.println(0);
            return;
        }

        int answer = n;

        for (int left = 0; left < n; left++) {

            for (int right = left; right < n; right++) {

                int[] temp = arr.clone();

                Arrays.sort(temp, left, right + 1);

                if (isSorted(temp)) {
                    answer = Math.min(answer, right - left + 1);
                }
            }
        }

        System.out.println(answer);
    }
    
}
/* 
Time Complexity: O(n^3)
Space Complexity: O(n)
*/
