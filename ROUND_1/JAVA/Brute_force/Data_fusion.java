package ROUND_1.JAVA.Brute_force;

import java.util.Scanner;

public class Data_fusion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums1 = new int[n];
        for (int i = 0; i < n; i++)
            nums1[i] = sc.nextInt();

        int m = sc.nextInt();
        int[] nums2 = new int[m];
        for (int i = 0; i < m; i++)
            nums2[i] = sc.nextInt();

        int[] merged = new int[n + m];

        int i = 0, j = 0, k = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j])
                merged[k++] = nums1[i++];
            else
                merged[k++] = nums2[j++];
        }

        while (i < n)
            merged[k++] = nums1[i++];

        while (j < m)
            merged[k++] = nums2[j++];

        int total = n + m;

        if (total % 2 == 1) {
            System.out.println(merged[total / 2]);
        } else {
            double median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;

            if (median == (int) median)
                System.out.println((int) median);
            else
                System.out.printf("%.1f\n", median);
        }

        sc.close();
    }
    
}
/*  
Complexity
Time: O(log(min(N, M)))
Space: O(1)
*/
