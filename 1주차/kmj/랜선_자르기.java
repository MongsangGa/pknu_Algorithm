import java.util.*;
import java.io.*;

class 랜선자르기 {

    private static int N;
    private static int[] lines;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        lines = new int[K];
        for(int i = 0; i < K; i++) {
            lines[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(lines);

        long start = 1;
        long end = lines[K-1];

        while(start <= end) {
            long mid = (start + end) / 2;
            if(canDivide(mid)) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        System.out.println(end);
    }

    static private boolean canDivide(long length) {
        long count = 0;
        for(int line : lines) {
            count += (line / length);
        }
        return count >= N;
    }
}
