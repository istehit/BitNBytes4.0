package ROUND_1.JAVA.Optimal;

import java.util.Scanner;

public class Production_line_recovery {
     public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int left = -1;
        int right = -1;

        int maxSeen = arr[0];

        for (int i = 1; i < n; i++) {

            maxSeen = Math.max(maxSeen, arr[i]);

            if (arr[i] < maxSeen)
                right = i;
        }

        if (right == -1) {
            System.out.println(0);
            return;
        }

        int minSeen = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            minSeen = Math.min(minSeen, arr[i]);

            if (arr[i] > minSeen)
                left = i;
        }

        System.out.println(right - left + 1);
    }
    
}
