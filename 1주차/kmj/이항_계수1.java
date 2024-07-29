import java.util.*;
import java.io.*;

public class 이항_계수1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int top = 1;
        int bottom = 1;

        for(int i = 1; i <= K; i++) {
            top *= N;
            N--;
            bottom *= i;
        }
        System.out.println(top / bottom);
    }
}