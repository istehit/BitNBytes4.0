
import java.io.*;
import java.util.*;


public class Energy_core_transfer {
   

    static long moves = 0;

    static void hanoi(int n, char from, char aux, char to) {

        if (n == 0)
            return;

        hanoi(n - 1, from, to, aux);

        moves++;

        hanoi(n - 1, aux, from, to);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        hanoi(n, 'A', 'B', 'C');

        System.out.println(moves);
    }
    
}
/* 
Time Complexity
O(2^n)     
Space Complexity
O(n)
*/

