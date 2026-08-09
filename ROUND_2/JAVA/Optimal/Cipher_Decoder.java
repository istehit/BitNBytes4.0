
import java.io.*;
import java.util.*;

public class Cipher_Decoder {
         public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String p = sc.next();

        int[] freq = new int[26];

        for (char c : p.toCharArray())
            freq[c - 'a']++;

        int left = 0;
        int count = p.length();

        int start = 0;
        int minLen = Integer.MAX_VALUE;

        for (int right = 0; right < s.length(); right++) {

            if (freq[s.charAt(right) - 'a'] > 0)
                count--;

            freq[s.charAt(right) - 'a']--;

            while (count == 0) {

                if (right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                freq[s.charAt(left) - 'a']++;

                if (freq[s.charAt(left) - 'a'] > 0)
                    count++;

                left++;
            }
        }

        if (minLen == Integer.MAX_VALUE)
            System.out.println("NONE");
        else
            System.out.println(s.substring(start, start + minLen));
    }
}
/* 
Time Complexity: O(n)
Space Complexity: O(1)
*/
