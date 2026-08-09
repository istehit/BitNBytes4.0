
import java.io.*;
import java.util.*;


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

        // Always binary search on the smaller array
        if (n > m) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;

            int t = n;
            n = m;
            m = t;
        }

        int low = 0;
        int high = n;

        while (low <= high) {

            int partitionX = (low + high) / 2;
            int partitionY = (n + m + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0)
                    ? Integer.MIN_VALUE
                    : nums1[partitionX - 1];

            int minRightX = (partitionX == n)
                    ? Integer.MAX_VALUE
                    : nums1[partitionX];

            int maxLeftY = (partitionY == 0)
                    ? Integer.MIN_VALUE
                    : nums2[partitionY - 1];

            int minRightY = (partitionY == m)
                    ? Integer.MAX_VALUE
                    : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {

                if ((n + m) % 2 == 0) {
                    double median = (Math.max(maxLeftX, maxLeftY)
                                   + Math.min(minRightX, minRightY)) / 2.0;

                    if (median == (int) median)
                        System.out.println((int) median);
                    else
                        System.out.printf("%.1f\n", median);

                } else {
                    System.out.println(Math.max(maxLeftX, maxLeftY));
                }

                return;
            }

            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }

            else {
                low = partitionX + 1;
            }
        }

        sc.close();
    }
    
}
/* 
Time Complexity
O(log(min(N, M)))
Space Complexity
O(1)
*/
