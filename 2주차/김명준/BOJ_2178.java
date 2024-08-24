import java.util.*;

// BOJ 2178 / 실버1 / 미로탐색 / 15분

class BOJ_2178 {

    private static int[][] arr;
    private static boolean[][] visited;
    private static int[] dx = { -1, 0, 1, 0 };
    private static int[] dy = { 0, -1, 0, 1 };
    private static int N;
    private static int M;

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        sc.nextLine();
        arr = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j)-'0';
                visited[i][j] = false;
            }
        }

        visited[0][0] = true;
        BFS(0, 0);
        System.out.println(arr[N - 1][M - 1]);
    }

    private static public void BFS(int x, int y) {

        Queue<Dot> q = new LinkedList<Dot>();
        q.add(new Dot(x, y));

        while (!q.isEmpty()) {
            Dot d = q.poll();

            for (int i = 0; i < 4; i++) {
                int nextX = d.x + dx[i];
                int nextY = d.y + dy[i];

                if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
                if (visited[nextX][nextY] || arr[nextX][nextY] == 0) continue;

                q.add(new Dot(nextX, nextY));
                arr[nextX][nextY] = arr[d.x][d.y] + 1;
                visited[nextX][nextY] = true;
            }
        }
    }
}

private static class Dot {
    int x;
    int y;

    Dot(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
}
