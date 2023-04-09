import java.util.Date;

public class BuiltInClass {
    private static final String STR = "A";

    public static String stringConcatenation() {
        String s = STR;
        for (int i = 0; i < 100000; i++)
            s = s + STR;
        return s;
    }

    public static String stringBufferConcatenation() {
        // java.lang.StringBuilder
        StringBuilder sb = new StringBuilder(STR);
        for (int i = 0; i < 100000; i++)
            sb.append(STR);
        return sb.toString();
    }

    public static void main(String[] args) {
        // java.lang.StringBuilder
        long start = System.currentTimeMillis();
        stringConcatenation();
        long end = System.currentTimeMillis();
        System.out.println("Thời gian dùng để ghép chuỗi String: " + (end - start) + "ms");
        start = System.currentTimeMillis();
        stringBufferConcatenation();
        end = System.currentTimeMillis();
        System.out.println("Thời gian dùng để ghép chuỗi dùng StringBuilder: "+ (end - start) + "ms");

        System.out.println(new Date()); // java.util.Date

        // java.lang.Math class
        double x = Math.random();
    }
}
