
class code {
    public static int solve(String s) {
        StringBuilder r = new StringBuilder(s);
        r.reverse();

        System.out.println(r.toString());

        int rp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == r.charAt(rp)) {
                System.out.println(i);
                rp++;
            }
        }
        return s.length() - rp;
    }

    public static void main(String[] args) {
        System.out.println(solve("00101011")); // 00110101
    }
}