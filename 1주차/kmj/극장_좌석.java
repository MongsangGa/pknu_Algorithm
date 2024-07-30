import java.util.*;
import java.io.*;

class 극장_좌석 {

    private static int dp[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        dp = new int[N+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int[] vips = new int[M];
        for(int i = 0; i < M; i++) {
            vips[i] =  Integer.parseInt(br.readLine());
        }

        long answer = 1;
        int previousVIP = 0;

        for (int i = 0; i < M; i++) {
            int gap = vips[i] - previousVIP - 1;
            answer *= dp[gap];
            previousVIP = vips[i];
        }

        int finalGap = N - previousVIP;
        answer *= dp[finalGap];

        System.out.println(answer);
    }
}