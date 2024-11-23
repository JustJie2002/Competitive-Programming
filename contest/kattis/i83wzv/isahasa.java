import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class isahasa {

    public record Entry(Set<String> isA, Set<String> hasA) {
        static Entry make() {
            return new Entry(new HashSet<>(), new HashSet<>());
        }
    }
    public static void main(String[] args) throws IOException{
        HashMap<String, Entry> all = new HashMap<>();
        BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
        String[] input=reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        for (int i = 0; i < n; i++) {
            input=reader.readLine().split(" ");
            String A = input[0];
            String type = input[1];
            String B = input[2];
            Entry e = all.computeIfAbsent(A, k -> Entry.make());
            if (type.equals("is-a")) e.isA.add(B);
            else e.hasA.add(B);
            all.computeIfAbsent(B, k -> Entry.make());
        }

        HashSet<String> seen = new HashSet<>();
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        Map<String, Boolean> cache = new HashMap<>();
        for (int i = 1; i <= m; i++) {
            seen.clear();
            input=reader.readLine().split(" ");
            String A = input[0];
            String type = input[1];
            String B = input[2];

            String key = A + "," + type + "," + B;
            String out = "Query " + i + ": ";
            if (cache.containsKey(key)) {
                out += cache.get(key);
            } else {
                Boolean answer = false;
                if (type.equals("is-a")) answer = isA(all, A, B);
                else answer = hasA(all, A, B, seen);
                out += answer;
                cache.put(key, answer);
            }
            writer.write(out+"\n");
        }
        writer.flush();
        reader.close();
    }

    public static boolean isA(Map<String,Entry> all, String A, String B) {
        if (A.equals(B)) return true;
        if (all.get(A).isA.contains(B)) return true;
        for (String subclass : all.get(A).isA) {
            if (isA(all, subclass, B)) return true;
        }
        return false;
    }

    public static  boolean hasA(Map<String,Entry> all, String A, String B, HashSet<String> seen) {
        if (seen.contains(A)) return false;
        seen.add(A);
        if (all.get(A).hasA.contains(B)) return true;

        for (String subclass : all.get(A).hasA) {
            if (isA(all, subclass, B)) return true;
            if (hasA(all, subclass, B, seen)) return true;
        }

        for (String subclass : all.get(A).isA) {
            if (hasA(all, subclass, B, seen)) return true;
        }
        return false;
    }
}
