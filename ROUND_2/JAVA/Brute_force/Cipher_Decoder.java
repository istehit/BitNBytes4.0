
import java.io.*;
import java.util.*;

public class Cipher_Decoder {
     static boolean isValid(String sub, String pattern) {

        int[] freq = new int[26];

        for (char c : pattern.toCharArray())
            freq[c - 'a']++;

        for (char c : sub.toCharArray())
            freq[c - 'a']--;

        for (int x : freq) {
            if (x > 0)
                return false;
        }

        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String p = sc.next();

        int minLength = Integer.MAX_VALUE;
        String answer = "";

        for (int i = 0; i < s.length(); i++) {

            for (int j = i; j < s.length(); j++) {

                String sub = s.substring(i, j + 1);

                if (isValid(sub, p)) {

                    if (sub.length() < minLength) {

                        minLength = sub.length();
                        answer = sub;
                    }
                }
            }
        }

        if (answer.isEmpty())
            System.out.println("NONE");
        else
            System.out.println(answer);
    }
    
}
/* 
Time Complexity: O(n^3)
Space Complexity: O(1)
*/
