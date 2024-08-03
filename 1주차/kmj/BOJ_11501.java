import java.util.*;
import java.io.*;

class BOJ_11501 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int jj = 0; jj < N; jj++) {

            int M = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int[] stocks = new int[M];
            for(int i = 0; i < M; i++) {
                stocks[i] = Integer.parseInt(st.nextToken());
            }

            long answer = 0;
            int maxStock = -1;
            for(int i = M -1; i >= 0; i--) {
                int nowStock = stocks[i];
                if(nowStock > maxStock) {
                    maxStock = nowStock;
                    continue;
                }

                if(nowStock < maxStock) {
                    answer += maxStock - nowStock;
                }
            }

            System.out.println(answer);
        }
    }
}