import java.io.*;
import java.util.*;

//골드 5 적록색약
public class BOJ10026 {

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static int gridSize;
    static char[][] colorGrid;
    static int[][] visited;
    static Deque<int[]> queue = new LinkedList<>();
    static int regionCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        gridSize = Integer.parseInt(br.readLine());
        colorGrid = new char[gridSize][gridSize];
        visited = new int[gridSize][gridSize];

        for (int i = 0; i < gridSize; i++) {
            String line = br.readLine();
            for (int j = 0; j < gridSize; j++) {
                colorGrid[i][j] = line.charAt(j);
            }
        }

        regionCount = 0;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (visited[i][j] == 0) {
                    regionCount++;
                    bfs(i, j);
                }
            }
        }
        System.out.print(regionCount + " ");

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (colorGrid[i][j] == 'R') {
                    colorGrid[i][j] = 'G';
                }
            }
        }

        visited = new int[gridSize][gridSize];
        regionCount = 0;

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (visited[i][j] == 0) {
                    regionCount++;
                    bfs(i, j);
                }
            }
        }
        System.out.println(regionCount);
    }

    public static void bfs(int startX, int startY) {
        queue.add(new int[]{startX, startY});
        visited[startX][startY] = regionCount;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];

            for (int i = 0; i < 4; i++) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];

                if (0 <= nextX && nextX < gridSize && 0 <= nextY && nextY < gridSize) {
                    if (colorGrid[nextX][nextY] == colorGrid[x][y] && visited[nextX][nextY] == 0) {
                        queue.add(new int[]{nextX, nextY});
                        visited[nextX][nextY] = regionCount;
                    }
                }
            }
        }
    }
}
