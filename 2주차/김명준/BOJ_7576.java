import java.io.*;
import java.util.*;

// BOJ 7576 / 골드5 / 토마토 / 15분

public class BOJ_7576 {
    private static int[] dy = { -1, 1, 0, 0 };
    private static int[] dx = { 0, 0, -1, 1 };
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[][] tomato = new int[N][M];

        int cnt = 0
        int days = 0;

        Queue<int[]> que = new LinkedList<>();
        for(int i = 0; i < N; i++) {

            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {

                tomato[i][j] = Integer.parseInt(st.nextToken());

                if (tomato[i][j] == 1)
                    que.add(new int[]{i, j});

                else if (tomato[i][j] == 0)
                    cnt++;
            }
        }

        while (cnt > 0 && !que.isEmpty()) {
            for (int s = que.size(); s > 0; s--) {
                int[] cur = que.poll();

                for (int k = 0; k < 4; k++) {
                    int ny = cur[0] + dy[k];
                    int nx = cur[1] + dx[k];

                    if (ny < 0 || nx < 0 || ny >= N || nx >= M || tomato[ny][nx] != 0)
                        continue;

                    cnt--;
                    tomato[ny][nx] = 1;
                    que.add(new int[] { ny, nx });
                }
            }
            days++;
        }
        System.out.println(cnt == 0 ? days : -1);
    }
}