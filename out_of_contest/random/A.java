
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {

    public static void main(String[] args) throws IOException{
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        
        PrintWriter out = new PrintWriter(System.out);

        Map<Integer, Integer> freq = new HashMap<>();
        int n = 3;
        int most = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            int sum = 0;
            while (x > 0) {
                sum += (x % 10);
                x /= 10;
            }
            freq.put(sum, freq.getOrDefault(sum, 0) + 1);
            most = Math.max(most, freq.get(sum));
        }

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            
        }

        out.close();
    }
}